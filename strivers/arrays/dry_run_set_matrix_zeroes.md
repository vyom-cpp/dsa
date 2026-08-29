# Matrix Zeroes Optimal - Dry Run Analysis

This file provides a line-by-line dry run of the provided `set_matrix_zeroes_optimal` function using a 4x4 matrix input.

---

## 1. Initial State
Before entering any loop execution blocks, the sizes and trackers are initialised.

*   **Dimensions:** `n = 4`, `m = 4`
*   **Flag Variable:** `col0 = 1`

### Input Matrix Layout
| | Col 0 | Col 1 | Col 2 | Col 3 |
|---|---|---|---|---|
| **Row 0** | 1 | 1 | 1 | 1 |
| **Row 1** | 1 | 0 | 0 | 1 |
| **Row 2** | 1 | 1 | 0 | 1 |
| **Row 3** | 1 | 1 | 1 | 1 |

---

## 2. Step 1: Marking Row & Column Flags
This nested loop scans the matrix from top to bottom, left to right. If `matrix[i][j] == 0`, it uses the first row (`matrix[0][j]`) and first column (`matrix[i][0]`) to store markers.

### Row i = 0
*   `j = 0`: `matrix[0][0]` is 1. No change.
*   `j = 1`: `matrix[0][1]` is 1. No change.
*   `j = 2`: `matrix[0][2]` is 1. No change.
*   `j = 3`: `matrix[0][3]` is 1. No change.

### Row i = 1
*   `j = 0`: `matrix[1][0]` is 1. No change.
*   `j = 1`: `matrix[1][1]` is 0. 
    *   Sets `matrix[1][0] = 0` (Row 1 tracker flag)
    *   Since `j != 0`, sets `matrix[0][1] = 0` (Col 1 tracker flag)
*   `j = 2`: `matrix[1][2]` is 0.
    *   Sets `matrix[1][0] = 0` (Row 1 tracker flag)
    *   Since `j != 0`, sets `matrix[0][2] = 0` (Col 2 tracker flag)
*   `j = 3`: `matrix[1][3]` is 1. No change.

### Row i = 2
*   `j = 0`: `matrix[2][0]` is 1. No change.
*   `j = 1`: `matrix[2][1]` is 1. No change.
*   `j = 2`: `matrix[2][2]` is 0.
    *   Sets `matrix[2][0] = 0` (Row 2 tracker flag)
    *   Since `j != 0`, sets `matrix[0][2] = 0` (Col 2 tracker flag)
*   `j = 3`: `matrix[2][3]` is 1. No change.

### Row i = 3
*   `j = 0`: `matrix[3][0]` is 1. No change.
*   `j = 1`: `matrix[3][1]` is 1. No change.
*   `j = 2`: `matrix[3][2]` is 1. No change.
*   `j = 3`: `matrix[3][3]` is 1. No change.

### Matrix State After Step 1 Flags
The embedded tracker markers are now set inside Row 0 and Column 0:
| | Col 0 | Col 1 | Col 2 | Col 3 |
|---|---|---|---|---|
| **Row 0** | 1 | **0** | **0** | 1 |
| **Row 1** | **0** | 0 | 0 | 1 |
| **Row 2** | **0** | 1 | 0 | 1 |
| **Row 3** | 1 | 1 | 1 | 1 |

---

## 3. Step 2: Updating the Inner Matrix
This block checks cells against their corresponding header flags `matrix[0][j]` or `matrix[i][0]`. If either flag is `0`, the inner element updates to `0`.

### Row i = 0
*   Skipped/Unaltered because updating headers here prematurely destroys tracking flags.

### Row i = 1
*   `j = 0`: `matrix[1][0]` is 0. Skips inner block condition.
*   `j = 1`: `matrix[1][1]` is 0. Skips inner block condition.
*   `j = 2`: `matrix[1][2]` is 0. Skips inner block condition.
*   `j = 3`: `matrix[1][3]` is 1. `matrix[1][0]` flag is 0. Updates `matrix[1][3] = 0`.

### Row i = 2
*   `j = 0`: `matrix[2][0]` is 0. Skips.
*   `j = 1`: `matrix[2][1]` is 1. `matrix[2][0]` flag is 0. Updates `matrix[2][1] = 0`.
*   `j = 2`: `matrix[2][2]` is 0. Skips.
*   `j = 3`: `matrix[2][3]` is 1. `matrix[2][0]` flag is 0. Updates `matrix[2][3] = 0`.

### Row i = 3
*   `j = 0`: `matrix[3][0]` is 1. Both flags are 1. No change.
*   `j = 1`: `matrix[3][1]` is 1. `matrix[0][1]` flag is 0. Updates `matrix[3][1] = 0`.
*   `j = 2`: `matrix[3][2]` is 1. `matrix[0][2]` flag is 0. Updates `matrix[3][2] = 0`.
*   `j = 3`: `matrix[3][3]` is 1. Both flags are 1. No change.

### Matrix State After Step 2 Inner Update
| | Col 0 | Col 1 | Col 2 | Col 3 |
|---|---|---|---|---|
| **Row 0** | 1 | 0 | 0 | 1 |
| **Row 1** | 0 | 0 | 0 | **0** |
| **Row 2** | 0 | **0** | 0 | **0** |
| **Row 3** | 1 | **0** | **0** | 1 |

---

## 4. Step 3: Flag Processing & Critical Bug Analysis
Your final tracking evaluation lines contain crucial **assignment operator bugs** (`=`) instead of relational comparison operators (`==`).

```cpp
if (matrix[0][0] = 0) { ... }
if (col0 = 0) { ... }
```

### Bug 1 Evaluation: `if (matrix[0][0] = 0)`
1.  **Action:** The statement executes an explicit assignment, overwriting `matrix[0][0]` with `0`.
2.  **Condition Assessment:** The assignment expression itself evaluates to its result (`0`), which maps directly to a **false** state in C++ conditionals.
3.  **Result:** The inner loop clearing Row 0 **fails to run**. Row 0 escapes being blanked, but its head cell `matrix[0][0]` is corrupted to `0`.

### Bug 2 Evaluation: `if (col0 = 0)`
1.  **Action:** The statement executes an explicit assignment, overwriting tracking variable `col0` with `0`.
2.  **Condition Assessment:** The assignment expression evaluates to `0` (**false**).
3.  **Result:** The inner loop clearing Column 0 **fails to run**. Column 0 is preserved in its modified partial flag state.

---

## 5. Final Output Matrix Layout
Because the final blocks failed their conditional evaluation blocks due to the `=` bug, the function returns this corrupted array state:

| | Col 0 | Col 1 | Col 2 | Col 3 |
|---|---|---|---|---|
| **Row 0** | **0** | 0 | 0 | 1 |
| **Row 1** | 0 | 0 | 0 | 0 |
| **Row 2** | 0 | 0 | 0 | 0 |
| **Row 3** | 1 | 0 | 0 | 1 |

---