
+++
authors = ["grid47"]
title = "Leetcode 19: Remove Nth Node From End of List"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 19: Remove Nth Node From End of List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/19.webp"
youtube = "XVuQxVej6y8"
youtube_upload_date="2020-12-29"
youtube_thumbnail="https://i.ytimg.com/vi/XVuQxVej6y8/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/19.webp" 
    alt="A single node being gently removed from a glowing chain, leaving a calm, uninterrupted flow."
    caption="Solution to LeetCode 19: Remove Nth Node From End of List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int sz = 0;
        while(node) {
            node = node->next;
            sz++;
        }
        node = head;
        int tgt = sz - n;
        if(sz == n) return head->next;
        for(int i = 0; i < tgt-1; i++)
            node = node->next;
        if(node->next)
        node->next = node->next->next;
        
        return head;
    }
};
{{< /highlight >}}
---

### 🎯 **Problem Statement: Remove the N-th Node from the End of a Linked List**

You are given a singly linked list and an integer `n`. Your task is to remove the **n-th node from the end of the list** and return the updated list. The list will always have at least one node, and the value of `n` is guaranteed to be valid.

#### Input:
- A singly linked list with at least one node.
- An integer `n`, which specifies the position of the node to remove, counted from the end of the list.

#### Output:
- A singly linked list with the `n-th` node removed.

The goal is to solve this problem efficiently, ideally in linear time complexity.

---

### 🧑‍💻 **Approach**

There are two main methods to solve this problem:

1. **Two-pass approach (Length-first)**:
   - **First pass**: Traverse the linked list to compute its length (`sz`).
   - **Second pass**: Traverse again to reach the node just before the one that needs to be removed (i.e., the `sz - n - 1` node), and adjust the `next` pointer to skip the target node.

2. **One-pass approach (Two pointers)**:
   - Use two pointers, `first` and `second`, such that the distance between them is always `n` nodes.
   - Move the `first` pointer `n` steps ahead, then move both pointers forward simultaneously. When `first` reaches the end, `second` will point to the node just before the one to be removed.

For simplicity, we will use the **two-pass approach**, which is more intuitive and easier to implement.

---

### 🧑‍💻 **Code Breakdown (Step by Step)**

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
```
- The function `removeNthFromEnd` takes the head of the linked list (`ListNode* head`) and an integer `n`, which indicates the position of the node to remove (counted from the end of the list).

```cpp
        ListNode* node = head;
        int sz = 0;
```
- `node` is a pointer to traverse the list, and `sz` stores the length of the list.

```cpp
        while(node) {
            node = node->next;
            sz++;
        }
```
- The first `while` loop traverses the entire list, counting the number of nodes by incrementing `sz`. After the loop, `sz` holds the length of the list.

```cpp
        node = head;
        int tgt = sz - n;
```
- We reset `node` to point back to the head. The target index (`tgt`) is calculated as `sz - n`, which points to the node just before the one we need to remove.

```cpp
        if(sz == n) return head->next;
```
- If `n` equals `sz`, this means the node to remove is the head of the list itself. In this case, we simply return `head->next`, effectively removing the head node.

```cpp
        for(int i = 0; i < tgt-1; i++)
            node = node->next;
```
- This loop moves `node` to the node just before the one we need to remove (i.e., `tgt - 1` steps).

```cpp
        if(node->next)
        node->next = node->next->next;
```
- After reaching the node just before the target, we update its `next` pointer to skip over the target node by linking to the node after it.

```cpp
        return head;
    }
};
```
- Finally, we return the updated head of the list. This might be the same as the original head if the target node was not the head, or a new head if the target node was the first one.

---

### ⏱️ **Time and Space Complexity**

#### Time Complexity:
- **First pass**: The first loop traverses the entire list to calculate the size, taking `O(N)` time, where `N` is the number of nodes in the list.
- **Second pass**: The second loop moves `tgt-1` steps to reach the node just before the one to be removed. In the worst case, this also takes `O(N)` time.

Thus, the overall **time complexity** is **O(N)**, where `N` is the length of the list.

#### Space Complexity:
- The space complexity is **O(1)** because the algorithm uses a constant amount of extra space for the `sz` variable and the `node` pointer. No additional data structures that grow with input size are used.

---

### 💡 **Conclusion**

This solution removes the `n-th` node from the end of a singly linked list in **O(N)** time and **O(1)** space. By calculating the list's length first and then finding the target node to remove, the algorithm is both simple and efficient. While the **one-pass approach** using two pointers can also be used, the two-pass approach is more intuitive and easier to implement.

**Key takeaways**:
- The first pass computes the length of the list.
- The second pass finds the node just before the one to be deleted and removes it.
- The updated list is returned, with the target node removed.

This solution is effective for typical use cases and handles edge cases, such as removing the head node, without added complexity.

Happy coding! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

---
{{< youtube XVuQxVej6y8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
