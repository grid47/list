
+++
authors = ["grid47"]
title = "Leetcode 876: Middle of the Linked List"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 876: Middle of the Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "-WV-G-QwB38"
youtube_upload_date="2023-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/-WV-G-QwB38/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // if(!fast)
            // return slow->next;
        return slow;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the middle node of a singly linked list. A singly linked list consists of nodes where each node has a value (`val`) and a pointer (`next`) to the next node in the list. The task is to return the middle node of the linked list.

If there are two middle nodes (in case of an even number of nodes), the second one should be returned.

### Example:

Given the linked list:

`1 -> 2 -> 3 -> 4 -> 5`

- **Input**: `head = [1, 2, 3, 4, 5]`
- **Output**: `[3, 4, 5]` (The middle node is `3` in this case)

For another linked list with an even number of nodes:

`1 -> 2 -> 3 -> 4 -> 5 -> 6`

- **Input**: `head = [1, 2, 3, 4, 5, 6]`
- **Output**: `[4, 5, 6]` (The middle node is `4`, the second of the two middle nodes)

### Approach

To solve this problem, we will use a **two-pointer technique** commonly referred to as the **Tortoise and Hare algorithm**. The idea is to use two pointers that traverse the linked list at different speeds. By the time the fast pointer reaches the end of the list, the slow pointer will be at the middle.

- **Fast Pointer (Hare)**: This pointer will move two steps at a time. It traverses the linked list at a faster pace.
- **Slow Pointer (Tortoise)**: This pointer will move one step at a time. It traverses the linked list at a slower pace.

### Key Insights:
1. The fast pointer moves twice as fast as the slow pointer. This means that when the fast pointer reaches the end of the list, the slow pointer will be positioned at the middle.
2. The approach works even for linked lists with an even number of nodes. If the list has an even length, the slow pointer will point to the second of the two middle nodes.

### Algorithm:
1. Initialize two pointers, `slow` and `fast`, both pointing to the head of the linked list.
2. Traverse the list with the `slow` pointer moving one step at a time and the `fast` pointer moving two steps at a time.
3. If the `fast` pointer reaches the end of the list (`fast == nullptr`), the `slow` pointer will be pointing at the middle node.
4. The algorithm terminates when the `fast` pointer cannot proceed further (i.e., when `fast` or `fast->next` is `nullptr`).

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Step 1: Initialize the slow and fast pointers.
        ListNode* slow = head, *fast = head;
        
        // Step 2: Traverse the list with the slow and fast pointers.
        // The slow pointer moves one step, and the fast pointer moves two steps.
        while (fast && fast->next) {
            slow = slow->next; // Move slow pointer by 1 step
            fast = fast->next->next; // Move fast pointer by 2 steps
        }
        
        // Step 3: Return the slow pointer when the fast pointer reaches the end.
        return slow;
    }
};
```

### Step-by-Step Explanation:

1. **Pointer Initialization**:
   - We initialize two pointers: `slow` and `fast`. Both are set to the head of the linked list.
   
   ```cpp
   ListNode* slow = head, *fast = head;
   ```

2. **Traversing the Linked List**:
   - We use a `while` loop to traverse the list. The loop continues until the `fast` pointer reaches the end of the list (i.e., `fast == nullptr`) or the `fast->next` pointer is `nullptr` (for the case when the number of nodes is odd).
   - Inside the loop:
     - The `slow` pointer moves one step forward by pointing to `slow->next`.
     - The `fast` pointer moves two steps forward by pointing to `fast->next->next`.
     
   ```cpp
   while (fast && fast->next) {
       slow = slow->next; // Move slow pointer by 1 step
       fast = fast->next->next; // Move fast pointer by 2 steps
   }
   ```

3. **Return the Middle Node**:
   - When the loop terminates, the `slow` pointer will be pointing to the middle node of the list. This is because the `fast` pointer has traversed the list twice as fast as the `slow` pointer, ensuring that when `fast` reaches the end, `slow` is at the middle.
   
   ```cpp
   return slow;
   ```

### Complexity Analysis

#### Time Complexity:
- **O(n)**: Both the `slow` and `fast` pointers traverse the list only once. Since the `fast` pointer moves twice as fast as the `slow` pointer, the total number of iterations is proportional to the length of the list, `n`. Hence, the time complexity is O(n), where `n` is the number of nodes in the linked list.

#### Space Complexity:
- **O(1)**: The space complexity is O(1) because we are using only two additional pointers (`slow` and `fast`) to traverse the list. No additional space is used that depends on the size of the input.

### Conclusion

This solution provides an efficient way to find the middle node of a singly linked list using the **Tortoise and Hare algorithm**, which operates in linear time and constant space. The two-pointer approach ensures that we traverse the list only once, making the algorithm highly efficient, even for large linked lists. 

- **Time Complexity**: O(n), where `n` is the number of nodes in the list.
- **Space Complexity**: O(1), as we use a constant amount of extra space.

This approach works perfectly for both odd and even length lists, making it a versatile solution for finding the middle node.

[`Link to LeetCode Lab`](https://leetcode.com/problems/middle-of-the-linked-list/description/)

---
{{< youtube -WV-G-QwB38 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
