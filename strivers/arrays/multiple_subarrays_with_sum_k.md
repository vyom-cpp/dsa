# Subarray Sum Equals K Optimal - Dry Run Analysis

This file provides a line-by-line dry run of the corrected `optimal` function which calculates the total number of subarrays whose sum equals $k$.

---

## 1. Initial State

Before entering the loop execution block, the frequency map, prefix sum tracker, and subarray counter are initialized based on the given input variables.

* **Input Array:** `arr = {3, -3, 1, 1, 1}`
* **Target Sum (kl):** `3`
* **Prefix Sum (preSum):** `0`
* **Subarray Counter (count):** `0`

### Map Initialization

A hash map `mpp` tracks the frequency of prefix sums encountered. The prefix sum of `0` is initialized to `1` to account for subarrays starting from index 0.

* `mpp = {0: 1}`

---

## 2. Loop Execution Block

The loop scans through the array from left to right (`i = 0` to `arr.size() - 1`), updating the running prefix sum, checking for valid subarrays, and updating the hash map frequency.

### Iteration i = 0

* **Current Element:** `arr[0] = 3`
* **Update Prefix Sum:** `preSum += arr[0]` → `preSum = 0 + 3 = 3`
* **Calculate Value to Remove:** `remove = preSum - kl` → `3 - 3 = 0`
* **Check Map for `remove` (0):** Found in `mpp` with a frequency of `1`.
* **Update Counter:** `count += mpp[0]` → `count = 0 + 1 = 1`
* **Update Map:** `mpp[preSum]++` → `mpp[3] = 1`
* **Current Map State:** `mpp = {0: 1, 3: 1}`

### Iteration i = 1

* **Current Element:** `arr[1] = -3`
* **Update Prefix Sum:** `preSum += arr[1]` → `preSum = 3 + (-3) = 0`
* **Calculate Value to Remove:** `remove = preSum - kl` → `0 - 3 = -3`
* **Check Map for `remove` (-3):** Not found in `mpp` (evaluates to `0`).
* **Update Counter:** `count += mpp[-3]` → `count = 1 + 0 = 1`
* **Update Map:** `mpp[preSum]++` → `mpp[0] = 2`
* **Current Map State:** `mpp = {0: 2, 3: 1, -3: 0}`

### Iteration i = 2

* **Current Element:** `arr[2] = 1`
* **Update Prefix Sum:** `preSum += arr[2]` → `preSum = 0 + 1 = 1`
* **Calculate Value to Remove:** `remove = preSum - kl` → `1 - 3 = -2`
* **Check Map for `remove` (-2):** Not found in `mpp` (evaluates to `0`).
* **Update Counter:** `count += mpp[-2]` → `count = 1 + 0 = 1`
* **Update Map:** `mpp[preSum]++` → `mpp[1] = 1`
* **Current Map State:** `mpp = {0: 2, 1: 1, 3: 1, -3: 0, -2: 0}`

### Iteration i = 3

* **Current Element:** `arr[3] = 1`
* **Update Prefix Sum:** `preSum += arr[3]` → `preSum = 1 + 1 = 2`
* **Calculate Value to Remove:** `remove = preSum - kl` → `2 - 3 = -1`
* **Check Map for `remove` (-1):** Not found in `mpp` (evaluates to `0`).
* **Update Counter:** `count += mpp[-1]` → `count = 1 + 0 = 1`
* **Update Map:** `mpp[preSum]++` → `mpp[2] = 1`
* **Current Map State:** `mpp = {0: 2, 1: 1, 2: 1, 3: 1, -3: 0, -2: 0, -1: 0}`

### Iteration i = 4

* **Current Element:** `arr[4] = 1`
* **Update Prefix Sum:** `preSum += arr[4]` → `preSum = 2 + 1 = 3`
* **Calculate Value to Remove:** `remove = preSum - kl` → `3 - 3 = 0`
* **Check Map for `remove` (0):** Found in `mpp` with a frequency of `2`.
* **Update Counter:** `count += mpp[0]` → `count = 1 + 2 = 3`
* **Update Map:** `mpp[preSum]++` → `mpp[3] = 2`
* **Current Map State:** `mpp = {0: 2, 1: 1, 2: 1, 3: 2, -3: 0, -2: 0, -1: 0}`

---

## 3. Subarray Validation Analysis

With the inclusion of `mpp[preSum]++`, the hash map correctly tracks all prefix sum occurrences and accounts for internal subarrays alongside prefix subarrays.

### Valid Subarrays Identified During Execution

1. **At index `i = 0`:**
* Found `mpp[0] = 1` → Identifies subarray `arr[0...0]` = `[3]` (Sum = 3).


2. **At index `i = 4`:**
* Found `mpp[0] = 2` → Accounts for two distinct prefix sum `0` occurrences:
* First occurrence (initial base `mpp[0]`): Identifies full prefix `arr[0...4]` = `[3, -3, 1, 1, 1]` (Sum = 3).
* Second occurrence (at index `1` where `preSum = 0`): Identifies internal slice `arr[2...4]` = `[1, 1, 1]` (Sum = 3).





---

## 4. Final Output & State Summary

### Final Variable State

* **Final `preSum`:** `3`
* **Returned `count`:** `3`

### Summary of Resulting Subarrays

* **Total Valid Subarrays:** `3`
1. `arr[0...0]` → `[3]`
2. `arr[2...4]` → `[1, 1, 1]`
3. `arr[0...4]` → `[3, -3, 1, 1, 1]`