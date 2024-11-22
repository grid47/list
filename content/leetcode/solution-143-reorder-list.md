
+++
authors = ["grid47"]
title = "Leetcode 143: Reorder List"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 143: Reorder List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers","Stack","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/143.webp"
youtube = "i3HU4Ur3-uM"
youtube_upload_date="2021-02-03"
youtube_thumbnail="https://i.ytimg.com/vi/i3HU4Ur3-uM/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/143.webp" 
    alt="A series of list items gently swapping positions, forming a balanced sequence."
    caption="Solution to LeetCode 143: Reorder List Problem"
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
    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* next, *prev = NULL;
        while(mid) {
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        ListNode* l1 = head, *l2 = prev;
        while(l1 && l2) {
            ListNode* tmp1 = l1->next;
            l1->next = l2;
            ListNode* tmp2 = l2->next;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};
{{< /highlight >}}
---

### 📝 **Problem Understanding: Reorder a Singly Linked List**

We are asked to reorder a singly linked list such that the nodes are arranged in an alternating order. Specifically, for a given linked list `L0 -> L1 -> L2 -> L3 -> ... -> Ln`, we want to reorder it as:

`L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...`.

#### Example Cases:
- **Input**: `head = [1, 2, 3, 4, 5]`
  - **Output**: `head = [1, 5, 2, 4, 3]`

- **Input**: `head = [1, 2, 3, 4]`
  - **Output**: `head = [1, 4, 2, 3]`

---

### 🔧 **Approach: Reordering the List**

The key to solving this problem is to:
1. Split the linked list into two halves.
2. Reverse the second half.
3. Merge the two halves in the alternating order.

#### Key Steps:
1. **Find the Middle of the List**: Use the slow and fast pointer technique to find the middle node of the list. The fast pointer moves two steps at a time, while the slow pointer moves one step at a time. By the time the fast pointer reaches the end, the slow pointer will be at the middle.

2. **Reverse the Second Half**: After finding the middle node, reverse the second half of the list. This can be done using a simple loop to reverse the `next` pointers of the nodes.

3. **Merge the Two Halves**: Once the second half is reversed, merge the two halves by alternating nodes from each half.

---

### 🖥️ **Code Breakdown: Step-by-Step**

#### Step 1: Finding the Middle of the List
```cpp
ListNode* fast = head, *slow = head;
while(fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
}
```
- We use two pointers: `slow` and `fast`, both initialized to the head of the list.
- The `fast` pointer moves two steps at a time, and the `slow` pointer moves one step at a time.
- The loop continues until the `fast` pointer reaches the end of the list, at which point the `slow` pointer will be at the middle of the list.

#### Step 2: Split the List and Reverse the Second Half
```cpp
ListNode* mid = slow->next;
slow->next = NULL;
ListNode* next, *prev = NULL;
while(mid) {
    next = mid->next;
    mid->next = prev;
    prev = mid;
    mid = next;
}
```
- After identifying the middle, we split the list into two halves. The first half goes from `head` to `slow`, and the second half starts from `slow->next`.
- We disconnect the first half by setting `slow->next = NULL`.
- Next, we reverse the second half by iterating through it and updating the `next` pointers.

#### Step 3: Merge the Two Halves
```cpp
ListNode* l1 = head, *l2 = prev;
while(l1 && l2) {
    ListNode* tmp1 = l1->next;
    l1->next = l2;
    ListNode* tmp2 = l2->next;
    l2->next = tmp1;
    l1 = tmp1;
    l2 = tmp2;
}
```
- After reversing the second half, we merge the two halves. We use two pointers: `l1` pointing to the first half and `l2` pointing to the reversed second half.
- In each iteration, we alternately attach nodes from `l1` and `l2`:
  - First, link `l1` to `l2`.
  - Then, link `l2` to the next node of `l1`.
- We continue this process until one of the halves is fully processed.

---

### 🧮 **Time and Space Complexity**

#### ⏱️ **Time Complexity**:
- **O(n)**: The algorithm consists of three main steps:
  1. Finding the middle of the list: **O(n)**.
  2. Reversing the second half: **O(n/2)**, which simplifies to **O(n)**.
  3. Merging the two halves: **O(n)**.
  
  The overall time complexity is linear, **O(n)**, where `n` is the number of nodes in the list.

#### 🧳 **Space Complexity**:
- **O(1)**: The algorithm only uses a fixed number of pointers and does not require extra data structures. Thus, the space complexity is constant, **O(1)**.

---

### 🎯 **Conclusion: Efficient Linked List Reordering**

This solution provides an optimal way to reorder a singly linked list in **O(n)** time and **O(1)** space. Here's why this approach works well:

1. **Time Efficiency**: The algorithm performs the key operations—finding the middle, reversing the second half, and merging the two halves—in linear time, **O(n)**.
2. **Space Efficiency**: The solution only uses a fixed number of pointers and does not require additional space or data structures.
3. **Simplicity and Optimality**: This approach efficiently handles the problem in-place without converting the list to other data structures.

#### Key Insights:
- **Efficient List Manipulation**: By splitting the list, reversing part of it, and merging the halves, we efficiently reorder the list with minimal complexity.
- **Optimal Solution**: The solution operates in linear time and uses constant space, making it ideal for handling large linked lists.

This technique is particularly useful when working with large linked lists, ensuring both quick execution and minimal memory usage.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reorder-list/description/)

---
{{< youtube i3HU4Ur3-uM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
