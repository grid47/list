
+++
authors = ["grid47"]
title = "Leetcode 2487: Remove Nodes From Linked List"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2487: Remove Nodes From Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Stack","Recursion","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "y783sRTezDg"
youtube_upload_date="2024-05-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/y783sRTezDg/maxresdefault.webp"
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
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return NULL;
        head->next = removeNodes(head->next);
        return head->next != NULL && head->val < head->next->val ? head->next: head;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves removing nodes from a singly linked list such that for any node, if its value is less than the value of the node that comes after it, it should be removed. This task is often referred to as eliminating nodes that are "less than" the next node in the list, ensuring that the resulting linked list remains in non-decreasing order.

Given a singly linked list where each node has a value and a pointer to the next node, the goal is to remove nodes such that the remaining nodes form a list where the value of each node is greater than or equal to the node that follows it.

For example, consider the list:

`1 -> 3 -> 2 -> 5 -> 4 -> NULL`

After removing the nodes that are less than the next node, the list should become:

`3 -> 5 -> NULL`

### Approach

The approach to solving this problem can be broken down into the following steps:

1. **Recursive Traversal**: Since the problem involves checking consecutive nodes in a list, it is well-suited for a recursive approach. We will recursively process the list from the end to the beginning.
  
2. **Reverse Order Processing**: In a recursive approach, we first reach the end of the list (base case), and then process the nodes while "unwinding" the recursive stack. This reverse order allows us to compare each node with its next node, making it easier to determine if the current node needs to be removed based on the value of the next node.

3. **Node Removal Condition**: As we traverse, we check if the current node's value is less than the value of the next node. If it is, the current node is removed. If it isn’t, we keep the current node in the list.

4. **Returning the Head**: The base case is when the list is empty (`head == NULL`), in which case we simply return `NULL`. For each recursive call, we decide whether to keep or remove the current node, and finally return the updated head of the list.

### Code Breakdown (Step by Step)

#### 1. **Base Case Handling**

```cpp
if (head == NULL) return NULL;
```

- This is the base case of the recursion. If the `head` of the list is `NULL`, it means we have reached the end of the list. In this case, we return `NULL`, signaling the end of the modified list.

#### 2. **Recursive Call**

```cpp
head->next = removeNodes(head->next);
```

- This line recursively calls `removeNodes` on the next node in the list. It keeps calling the function until the end of the list is reached (base case). As the recursion unwinds, it starts comparing nodes and deciding whether to keep or remove them.

#### 3. **Node Removal Decision**

```cpp
return head->next != NULL && head->val < head->next->val ? head->next : head;
```

- Once the recursive call is made and the next node is processed, we compare the current node (`head`) with the next node (`head->next`).
- The condition `head->next != NULL && head->val < head->next->val` checks if the current node’s value is smaller than the next node’s value.
  - If the condition is true, it means the current node should be removed. We return `head->next`, effectively removing the current node.
  - If the condition is false, the current node is kept in the list, and we return `head`.

#### 4. **Function Return**

At the end of the recursion, the head of the modified list is returned. This head will either be the same as the initial head or will have changed based on the removal of certain nodes.

### Complexity Analysis

#### Time Complexity:
The time complexity of the solution is **O(n)**, where `n` is the number of nodes in the linked list. This is because the function makes one pass through the entire list, and each node is processed once. Specifically:
- Each recursive call processes a single node.
- The list is traversed once to modify the nodes.

Therefore, the time complexity is **O(n)**, where `n` is the number of nodes in the list.

#### Space Complexity:
The space complexity is **O(n)** due to the recursive call stack. In the worst case, the recursion depth can go as deep as the number of nodes in the linked list. Thus, the space complexity is proportional to the number of nodes.

### Conclusion

This solution efficiently solves the problem by using a recursive approach to traverse the list in reverse order. By using recursion, we process each node starting from the end of the list, making it easy to decide whether to remove a node based on the value of the node that follows it. 

The algorithm operates with linear time complexity **O(n)** and space complexity **O(n)** due to the recursive stack. This approach ensures that nodes which violate the condition (having a value smaller than the next node) are removed, and the resulting list maintains a non-decreasing order. 

The solution is both simple and effective for problems that require processing linked lists in a sequential manner, especially when recursion provides a natural way to traverse the list.

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-nodes-from-linked-list/description/)

---
{{< youtube y783sRTezDg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
