# Dry Run Analysis: Deleting N-th Node from End of Linked List

This document provides a comparative dry run of the `optimal` function to demonstrate why using `while(fast != nullptr)` instead of `while(fast->next != nullptr)` causes an incorrect deletion.

### Setup Information
* **Linked List:** `1 -> 2 -> 3 -> 4 -> 5 -> nullptr`
* **k:** `2` (We want to delete the 2nd node from the end, which is `4`)
* **Expected Output:** `1 -> 2 -> 3 -> 5`

---

## Case 1: Original Code (Correct)
```cpp
while(fast->next != nullptr){
    slow = slow->next;
    fast = fast->next;
}
```

### Initial State (After the first `while(k != 0)` loop moves `fast` ahead by 2 steps):
* `slow` points to node `1`
* `fast` points to node `3`

### Loop Execution:

| Iteration | Initial Node Positions | Condition Check (`fast->next != nullptr`) | Action Taken | Resulting Positions |
| :---: | :--- | :--- | :--- | :--- |
| **1** | `slow` at `1`, `fast` at `3` | `3->next` (`4`) `nullptr` -> **True** | Move both pointers forward | `slow` at `2`, `fast` at `4` |
| **2** | `slow` at `2`, `fast` at `4` | `4->next` (`5`) `nullptr` -> **True** | Move both pointers forward | `slow` at `3`, `fast` at `5` |
| **3** | `slow` at `3`, `fast` at `5` | `5->next` is `nullptr` -> **False** | **Loop Terminates** | `slow` stops at `3`, `fast` stops at `5` |

### Post-Loop Deletion:
* `slow` is at `3`.
* `Node* dltNode = slow->next;` -> `dltNode` points to `4`.
* `slow->next = slow->next->next;` -> Node `3` links to node `5`.
* `delete dltNode;` -> Node `4` is deleted.
* **Output:** `1 -> 2 -> 3 -> 5` (Correct)

---

## Case 2: Buggy Code
```cpp
while(fast != nullptr){
    slow = slow->next;
    fast = fast->next;
}
```

### Initial State:
* `slow` points to node `1`
* `fast` points to node `3`

### Loop Execution:

| Iteration | Initial Node Positions | Condition Check (`fast != nullptr`) | Action Taken | Resulting Positions |
| :---: | :--- | :--- | :--- | :--- |
| **1** | `slow` at `1`, `fast` at `3` | `3` `nullptr` -> **True** | Move both pointers forward | `slow` at `2`, `fast` at `4` |
| **2** | `slow` at `2`, `fast` at `4` | `4` `nullptr` -> **True** | Move both pointers forward | `slow` at `3`, `fast` at `5` |
| **3** | `slow` at `3`, `fast` at `5` | `5` `nullptr` -> **True** | Move both pointers forward | `slow` at `4`, `fast` at `nullptr` |
| **4** | `slow` at `4`, `fast` at `nullptr` | `fast` is `nullptr` -> **False** | **Loop Terminates** | `slow` stops at `4`, `fast` stops at `nullptr` |

### Post-Loop Deletion:
* `slow` is at `4`.
* `Node* dltNode = slow->next;` -> `dltNode` points to `5`.
* `slow->next = slow->next->next;` -> Node `4` links to `nullptr`.
* `delete dltNode;` -> Node `5` is deleted.
* **Output:** `1 -> 2 -> 3 -> 4` (Incorrect - deleted the 1st node from the end instead of the 2nd)

---

## Key Takeaway
To delete a node in a singly linked list, **`slow` must stop at the node immediately before the target node**. 
* `fast->next != nullptr` stops `fast` at the last node (`5`), positioning `slow` perfectly at node `3` (just before target node `4`).
* `fast != nullptr` forces the loop to run one extra time until `fast` falls off the list (`nullptr`), accidentally pushing `slow` to node `4`.
