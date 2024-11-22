
+++
authors = ["grid47"]
title = "Leetcode 142: Linked List Cycle II"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 142: Linked List Cycle II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/142.webp"
youtube = "Yn5xqbK95Uw"
youtube_upload_date="2020-10-27"
youtube_thumbnail="https://i.ytimg.com/vi/Yn5xqbK95Uw/sddefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/142.webp" 
    alt="A cycle in the linked list gently glowing, with the starting node illuminated to indicate the cycle's start."
    caption="Solution to LeetCode 142: Linked List Cycle II Problem"
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *fast = head, *slow= head;
        while(fast && fast->next) {
            
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;
        }
        if(!(fast && fast->next)) return NULL;
        
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
{{< /highlight >}}
---

### 🧩 **Problem Understanding: Detect the Start of a Cycle in a Linked List**

In this problem, we're tasked with detecting the node at which a cycle begins in a singly linked list. A cycle occurs when a node's `next` pointer points to one of the earlier nodes, forming a loop. Our goal is to return the node where the cycle starts, or `NULL` if there is no cycle.

#### Example Cases:
- **Input**: `head = [3, 2, 0, -4]`, `pos = 1` (where `pos` indicates the node where the cycle starts).
- **Output**: The node at index 1 (value `2`), as it points back to itself, forming a cycle.

- **Input**: `head = [1, 2]`, `pos = -1` (indicating no cycle).
- **Output**: `NULL` (no cycle).

---

### 🔄 **Approach: Floyd’s Cycle-Finding Algorithm (Tortoise and Hare)**

To detect the node where a cycle starts, we can modify **Floyd’s Cycle-Finding Algorithm**. This method uses two pointers, known as the slow pointer (`tortoise`) and the fast pointer (`hare`), which move at different speeds to both detect a cycle and find its start.

#### Key Concepts:
1. **Cycle Detection**: We use the **Floyd’s Cycle-Finding Algorithm** to check if a cycle exists.
   - The **slow pointer** moves one step at a time.
   - The **fast pointer** moves two steps at a time.
   
2. **Cycle Start Detection**: Once we detect a cycle, we reset one pointer to the head of the list and leave the other pointer at the point where they met. Both pointers are then moved one step at a time until they meet again. The node where they meet is the start of the cycle.

---

### 🖥️ **Code Breakdown: Step-by-Step**

#### Step 1: Initial Setup and Edge Case Handling
```cpp
ListNode *detectCycle(ListNode *head) {
    if(head == NULL) return NULL;
```
- We first handle the edge case where the list is empty (`head == NULL`), in which case there is no cycle, so we return `NULL`.

#### Step 2: Initialize Slow and Fast Pointers
```cpp
    ListNode *fast = head, *slow = head;
    while(fast && fast->next) {
```
- We initialize two pointers, `slow` and `fast`, both starting at the head of the list.
- The `while` loop continues as long as `fast` and `fast->next` are not `NULL`, ensuring there are at least two nodes for the fast pointer to move.

#### Step 3: Detect the Cycle
```cpp
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) break;
```
- Inside the loop:
  - The `slow` pointer moves one step (`slow = slow->next`).
  - The `fast` pointer moves two steps (`fast = fast->next->next`).
- If at any point the `fast` pointer meets the `slow` pointer (`fast == slow`), a cycle is detected, and we exit the loop.

#### Step 4: No Cycle Found
```cpp
    if(!(fast && fast->next)) return NULL;
```
- If the `fast` pointer reaches the end of the list (`fast == NULL` or `fast->next == NULL`), it indicates that there is no cycle in the list, so we return `NULL`.

#### Step 5: Find the Start of the Cycle
```cpp
    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }
```
- After detecting a cycle, we reset one pointer (`head`) to the start of the list, while the `slow` pointer stays at the meeting point inside the cycle.
- Both pointers move one step at a time until they meet. The node where they meet is the start of the cycle.

#### Step 6: Return the Cycle Start
```cpp
    return slow;
}
```
- Once the pointers meet, we return the `slow` pointer, which points to the node at the start of the cycle.

---

### 🧮 **Time and Space Complexity**

#### ⏱️ **Time Complexity**:
- **O(n)**: In the worst case, both the slow and fast pointers traverse the list and detect the cycle. Afterward, they move through the cycle and meet at the start node. The overall time complexity is linear, O(n), where `n` is the number of nodes in the list.

#### 🧳 **Space Complexity**:
- **O(1)**: The algorithm uses only two pointers (`slow` and `fast`), requiring constant space. Therefore, the space complexity is O(1).

---

### 🎯 **Conclusion: Efficient Cycle Detection and Start Detection**

This solution efficiently detects the node where a cycle begins in a singly linked list using **Floyd’s Cycle-Finding Algorithm**. Here’s why this approach is optimal:

1. **Time Efficiency**: The algorithm runs in linear time, O(n), where `n` is the number of nodes in the list. It efficiently detects both the cycle and the start node.
2. **Space Efficiency**: The solution uses constant space, O(1), by relying only on two pointers, regardless of the list size.
3. **Cycle Detection and Start Detection**: By using the two-pointer technique, we not only detect the cycle but also pinpoint the node where the cycle begins without additional data structures or modifications.

#### Key Insights:
- **Two-Pointer Technique**: The combination of slow and fast pointers ensures that we can efficiently detect both the presence and the start of the cycle.
- **Optimal Solution**: The solution is optimal in terms of both time and space complexity for detecting cycles and finding the start node in a singly linked list.

This approach is widely used in problems involving cycle detection in linked lists and provides an efficient and reliable solution.

[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-cycle-ii/description/)

---
{{< youtube Yn5xqbK95Uw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
