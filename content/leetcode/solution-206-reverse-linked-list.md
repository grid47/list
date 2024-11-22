
+++
authors = ["grid47"]
title = "Leetcode 206: Reverse Linked List"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 206: Reverse Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/206.webp"
youtube = "W-EfGB0E_ao"
youtube_upload_date="2020-02-08"
youtube_thumbnail="https://i.ytimg.com/vi/W-EfGB0E_ao/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/206.webp" 
    alt="A linked list where nodes glow and reverse in position, flowing smoothly backward."
    caption="Solution to LeetCode 206: Reverse Linked List Problem"
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
    ListNode* reverseList(ListNode* head) {
        ListNode* nxt, *prv = NULL;
        while(head) {
            nxt = head->next;
            head->next = prv;
            prv = head;
            head = nxt;
        }
        return prv;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

Let’s dive into the **Reversing a Singly Linked List** problem! 🔄 Given the head of a singly linked list, your task is to reverse the list so that the first node becomes the last, and the last node becomes the first. We need to return the head of the reversed list after performing the operation.

#### Example:
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `head = [5, 4, 3, 2, 1]`

This problem is about efficiently reversing the linked list with linear time complexity and constant space. Let's break it down! 💡

---

### 🔍 Approach

We can solve this problem using an **iterative approach** by keeping track of three pointers:
1. **`head`**: Initially points to the first node of the list.
2. **`prv`** (previous): Initially set to `nullptr` since the new tail will point to `nullptr`.
3. **`nxt`** (next): Temporarily stores the next node while we adjust the `next` pointers.

Here’s the game plan:
1. Set up the pointers (`head`, `prv`, and `nxt`).
2. Traverse the list, reverse the pointers one by one.
3. Return the new head when the list is fully reversed.

Let’s look at the detailed steps! 🧠

---

### 🔨 Step-by-Step Code Breakdown

#### Step 1: Initialize Pointers
```cpp
ListNode* nxt, *prv = NULL;
```
- **`nxt`**: A temporary pointer to store the next node of the list.
- **`prv`**: Initially set to `nullptr`, which will eventually become the new head of the reversed list.

#### Step 2: Traverse the List
```cpp
while (head) {
    nxt = head->next;   // Store the next node temporarily
    head->next = prv;    // Reverse the current node's next pointer
    prv = head;          // Move `prv` to the current node
    head = nxt;          // Move to the next node in the list
}
```
- **Loop condition:** We continue until we reach the end of the list (`head` becomes `nullptr`).
- **`nxt = head->next`:** Store the next node so we don't lose the rest of the list.
- **`head->next = prv`:** Reverse the current node's `next` pointer to point to the previous node.
- **`prv = head`:** Move the `prv` pointer to the current node.
- **`head = nxt`:** Move to the next node, stored in `nxt`.

#### Step 3: Return the New Head
```cpp
return prv;
```
- Once the loop finishes, `prv` will point to the new head of the reversed list. Return it to complete the process! 🎉

---

### 📊 Complexity Analysis

Let’s analyze the time and space complexity of this solution. ⏱️💾

#### Time Complexity:
- **O(n):** 
  - We traverse the entire list once, visiting each node exactly once. For each node, we perform constant-time operations (updating pointers), so the time complexity is **O(n)**, where `n` is the number of nodes in the list.

#### Space Complexity:
- **O(1):**
  - The space complexity is constant because we only use a few extra pointers (`prv`, `nxt`), regardless of the list size. No additional data structures are used, so the space complexity remains **O(1)**.

---

### 🏁 Conclusion

In conclusion, we’ve successfully reversed the singly linked list using an efficient iterative approach! 🚀 Here’s a quick summary:

1. **Time Efficiency:** The algorithm runs in **O(n)**, which is optimal since we must traverse each node.
2. **Space Efficiency:** The solution uses constant space **O(1)**, making it perfect for large lists.
3. **Simplicity:** The iterative approach is easy to implement, avoiding recursion and keeping things simple.

This solution is perfect when you need to reverse a linked list in the most efficient way possible. Keep practicing, and you’ll become a linked list pro in no time! 💪✨

[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-linked-list/description/)

---
{{< youtube W-EfGB0E_ao >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
