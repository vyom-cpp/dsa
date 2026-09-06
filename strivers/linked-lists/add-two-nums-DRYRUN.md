# Add Two Numbers Represented by Linked Lists - Dry Run Analysis

This file provides a comprehensive, step-by-step dry run of the `addison` (Add Two Numbers) function implemented in C++.

---

## 1. Problem Context & Representation

In this problem, non-empty linked lists represent two non-negative integers. The digits are stored in **reverse order** (least significant digit to most significant digit at the head).

* **Input 1:** `arr1 = [2, 4, 6]` → represents the number **642**
* **Input 2:** `arr2 = [3, 8, 7]` → represents the number **783**
* **Expected Output Linked List:** `5 -> 2 -> 4 -> 1 -> nullptr` (representing digits of 1425 in reverse order).

---

## 2. Initial State

Before entering the addition loop in `addison(head1, head2)`:

* **List 1 (`num1` / `t1`):** `[2] -> [4] -> [6] -> nullptr`
* **List 2 (`num2` / `t2`):** `[3] -> [8] -> [7] -> nullptr`
* **Dummy Node Created:** `dummyHead` with `data = -1`, `next = nullptr`
* **Pointers Initialized:**
  * `current = dummyHead`
  * `t1 = num1` (pointing to node with value `2`)
  * `t2 = num2` (pointing to node with value `3`)
* **Carry Initialized:** `carry = 0`

---

## 3. Step-by-Step Loop Execution

The loop runs as long as `(t1 != NULL || t2 != NULL)`.

```cpp
while (t1 != NULL || t2 != NULL) {
    int sum = carry;
    if (t1) sum += t1->data;
    if (t2) sum += t2->data;
    Node* nn = new Node(sum % 10);
    carry = sum / 10;
    current->next = nn;
    current = current->next;
    if (t1) t1 = t1->next;
    if (t2) t2 = t2->next;
}

```

### Iteration 1

* **Condition Check:** `t1 != NULL` (points to `2`), `t2 != NULL` (points to `3`) → **True**
* **Calculate Sum:**
* `sum = carry` → 0
* `t1` is valid: `sum += 2` → 2
* `t2` is valid: `sum += 3` → 5


* **Create New Node (`nn`):** `new Node(5 % 10)` → `new Node(5)`
* **Update Carry:** `carry = 5 / 10` → 0
* **Attach Node:** `current->next = nn` → `dummyHead -> [5]`
* **Advance Pointer:** `current` moves to node `[5]`
* **Advance Inputs:**
* `t1` moves to `[4]`
* `t2` moves to `[8]`



---

### Iteration 2

* **Condition Check:** `t1 != NULL` (points to `4`), `t2 != NULL` (points to `8`) → **True**
* **Calculate Sum:**
* `sum = carry` → 0
* `t1` is valid: `sum += 4` → 4
* `t2` is valid: `sum += 8` → 12


* **Create New Node (`nn`):** `new Node(12 % 10)` → `new Node(2)`
* **Update Carry:** `carry = 12 / 10` → 1
* **Attach Node:** `current->next = nn` → `dummyHead -> [5] -> [2]`
* **Advance Pointer:** `current` moves to node `[2]`
* **Advance Inputs:**
* `t1` moves to `[6]`
* `t2` moves to `[7]`



---

### Iteration 3

* **Condition Check:** `t1 != NULL` (points to `6`), `t2 != NULL` (points to `7`) → **True**
* **Calculate Sum:**
* `sum = carry` → 1
* `t1` is valid: `sum += 6` → 7
* `t2` is valid: `sum += 7` → 14


* **Create New Node (`nn`):** `new Node(14 % 10)` → `new Node(4)`
* **Update Carry:** `carry = 14 / 10` → 1
* **Attach Node:** `current->next = nn` → `dummyHead -> [5] -> [2] -> [4]`
* **Advance Pointer:** `current` moves to node `[4]`
* **Advance Inputs:**
* `t1` moves to `nullptr`
* `t2` moves to `nullptr`



---

## 4. Loop Termination & Post-Processing

* **Condition Check:** `t1 == NULL` and `t2 == NULL` → Loop terminates.
* **Carry Check (`if (carry)`):**
* `carry = 1` (non-zero)
* `Node* nn = new Node(1)`
* `current->next = nn` → attaches node `[1]` to the end.


* **Result Pointer:** Return `dummyHead->next`, which points to the head node `[5]`.

---

## 5. Execution Trace Table

| Iteration | `t1->data` | `t2->data` | Old `carry` | Total `sum` | Node Created (`sum % 10`) | New `carry` (`sum / 10`) | Result List State |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **Init** | - | - | - | - | - | 0 | `dummyHead(-1)` |
| **1** | 2 | 3 | 0 | 5 | **5** | 0 | `[-1] -> [5]` |
| **2** | 4 | 8 | 0 | 12 | **2** | 1 | `[-1] -> [5] -> [2]` |
| **3** | 6 | 7 | 1 | 14 | **4** | 1 | `[-1] -> [5] -> [2] -> [4]` |
| **Post** | - | - | 1 | - | **1** | 0 | `[-1] -> [5] -> [2] -> [4] -> [1]` |

---

## 6. Final Output & Complexity Analysis

### Final Console Output

```text
5 2 4 1 

```

### Complexity

* **Time Complexity:** max(N, M) where N and M are the lengths of `num1` and `num2` respectively. Each node is visited once.
* **Space Complexity:** max(N, M) to store the resulting linked list nodes.

```