
+++
authors = ["grid47"]
title = "Leetcode 141: Linked List Cycle"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 141: Linked List Cycle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/141.webp"
youtube = "6OrZ4wAy4uE"
youtube_upload_date="2019-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6OrZ4wAy4uE/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/141.webp" 
    alt="A circular linked list glowing in a cycle, with the loop softly visible."
    caption="Solution to LeetCode 141: Linked List Cycle Problem"
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
{{< /highlight >}}
---

### 🧩 **Understanding the Problem: Detect Cycle in Linked List**

The problem asks us to determine whether a given singly linked list contains a cycle. A cycle in a linked list occurs when a node’s `next` pointer points to one of the previous nodes, forming a loop. The goal is to return `true` if the linked list has a cycle and `false` otherwise.

For example:
- **Input**: `head = [3, 2, 0, -4]`, `pos = 1` (where `pos` indicates the node at which the cycle starts).
- **Output**: `true` (since the node at index 1 points back to itself, forming a cycle).

- **Input**: `head = [1, 2]`, `pos = -1`.
- **Output**: `false` (no cycle).

---

### 🔄 **Approach: Floyd’s Cycle-Finding Algorithm (Tortoise and Hare)**

To detect a cycle in a singly linked list, we can use **Floyd’s Cycle-Finding Algorithm**, also known as the **Tortoise and Hare** algorithm. This algorithm utilizes two pointers:
1. A **slow pointer** (`tortoise`) that moves one step at a time.
2. A **fast pointer** (`hare`) that moves two steps at a time.

#### Key Ideas:
- **If a cycle exists**: The fast pointer will eventually catch up with the slow pointer within the cycle.
- **If no cycle**: The fast pointer will reach the end of the list.

#### Key Steps:
1. **Initialization**: Both the slow and fast pointers start at the head of the list.
2. **Traversal**: In each iteration, the slow pointer moves one step, and the fast pointer moves two steps.
3. **Cycle Detection**: If the slow pointer and the fast pointer meet at any point, a cycle exists, and we return `true`.
4. **End of List**: If the fast pointer reaches the end of the list (`fast == NULL` or `fast->next == NULL`), we return `false`, indicating that there is no cycle.

---

### 🖥️ **Code Breakdown: Step-by-Step**

#### 1️⃣ **Function Definition and Initialization**

```cpp
bool hasCycle(ListNode *head) {
    ListNode* slow = head, *fast = head;
```
- The function `hasCycle` takes a pointer `head` to the first node of the linked list.
- We initialize two pointers, `slow` and `fast`, both pointing to the `head` of the list. The `slow` pointer moves one step at a time, while the `fast` pointer moves two steps at a time.

#### 2️⃣ **Traversing the List**

```cpp
while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
```
- The `while` loop ensures that we continue traversing as long as `fast` and `fast->next` are not `NULL`. If `fast` reaches `NULL`, there’s no cycle, and we can return `false`.
- Inside the loop:
  - The `slow` pointer advances by one node: `slow = slow->next`.
  - The `fast` pointer advances by two nodes: `fast = fast->next->next`.

#### 3️⃣ **Cycle Detection**

```cpp
if(slow == fast) return true;
```
- After advancing both pointers, we check if `slow` and `fast` are pointing to the same node. If they are, it means the fast pointer has caught up with the slow pointer inside the cycle, indicating that a cycle exists. We return `true`.

#### 4️⃣ **End of the List**

```cpp
return false;
```
- If the fast pointer reaches the end of the list (`fast == NULL` or `fast->next == NULL`), we return `false` because the list doesn’t have a cycle.

---

### 🧮 **Time and Space Complexity**

#### ⏱️ **Time Complexity**:
- **O(n)**: In the worst case, the fast pointer will traverse the list at most twice: once moving two steps per iteration and then meeting the slow pointer. This gives a linear time complexity, O(n), where `n` is the number of nodes in the list.

#### 🧳 **Space Complexity**:
- **O(1)**: We only use two pointers (`slow` and `fast`), and the algorithm doesn’t require any additional space that grows with the size of the input. Hence, the space complexity is constant, O(1).

---

### 🎯 **Conclusion: Efficient Cycle Detection**

Floyd’s Cycle-Finding Algorithm (Tortoise and Hare) efficiently detects whether a singly linked list contains a cycle. Here’s why this approach is optimal:

1. **Time Efficiency**: The algorithm runs in linear time, O(n), where `n` is the number of nodes. This is optimal because each node is visited at most once.
2. **Space Efficiency**: The solution uses constant space, O(1), as it only requires two pointers regardless of the size of the list.
3. **Simplicity**: This approach is easy to implement and avoids the need for extra space, such as a hash set or modifying the list structure.

#### Key Insights:
- **Fast and Slow Pointers**: The crux of this algorithm is the two-pointer approach, where one pointer moves faster than the other, helping us detect cycles when the fast pointer eventually meets the slow pointer.
- **Optimal Solution**: The algorithm is optimal for cycle detection due to its linear time complexity and constant space usage.

In conclusion, this is a highly efficient and widely-used algorithm for cycle detection in linked lists.

[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-cycle/description/)

---
{{< youtube 6OrZ4wAy4uE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
