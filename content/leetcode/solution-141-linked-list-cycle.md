
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
comments = true
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
Given the head of a linked list, determine if there is a cycle. A cycle occurs if a node can be revisited by following the 'next' pointers. The 'pos' parameter denotes where the last node connects to. If 'pos' is -1, there is no cycle.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a linked list head and a position, 'pos', indicating where the tail node connects.
- **Example:** `Input: head = [4, 3, 2, 1], pos = 2`
- **Constraints:**
	- The number of nodes in the list is between 0 and 10^4.
	- Node values range between -10^5 and 10^5.
	- 'pos' is either -1 or a valid index within the list.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value indicating whether a cycle exists in the linked list.
- **Example:** `Output: true`
- **Constraints:**
	- The output is true if a cycle exists, otherwise false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to detect if there is a cycle in the linked list using efficient memory usage.

- 1. Use two pointers, 'slow' and 'fast', where 'slow' moves one step and 'fast' moves two steps at a time.
- 2. If there is a cycle, the two pointers will meet; otherwise, the fast pointer will reach the end of the list.
{{< dots >}}
### Problem Assumptions ✅
- The linked list can have a cycle, or it can be a simple acyclic list.
- All nodes contain integer values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [4, 3, 2, 1], pos = 2`  \
  **Explanation:** In this example, the tail node points to the 2nd node, forming a cycle.

{{< dots >}}
## Approach 🚀
The approach leverages the Floyd's Cycle-Finding Algorithm (also known as the Tortoise and Hare algorithm), using two pointers to detect cycles in constant space.

### Initial Thoughts 💭
- We need to detect a cycle using minimal space, ideally O(1).
- By using two pointers, one slow and one fast, we can determine if there is a cycle without using additional data structures.
{{< dots >}}
### Edge Cases 🌐
- An empty list should return false since no cycle can exist.
- For large lists, the solution should efficiently detect cycles without using extra memory.
- When the cycle starts at the very first node or is self-referential (the last node points to itself).
- Ensure constant space usage (O(1)) and linear time complexity (O(n)) for large inputs.
{{< dots >}}
## Code 💻
```cpp
bool hasCycle(ListNode *head) {
    ListNode* slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
```

This code implements Floyd’s Cycle Detection Algorithm (also known as the Tortoise and Hare algorithm) to detect a cycle in a linked list. It uses two pointers: one moves slowly and the other moves quickly. If they meet, a cycle exists in the list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool hasCycle(ListNode *head) {
	```
	This is the definition of the `hasCycle` function, which takes a pointer `head` to the first node of a linked list and returns a boolean indicating whether the list contains a cycle.

2. **Pointer Initialization**
	```cpp
	    ListNode* slow = head, *fast = head;
	```
	Two pointers, `slow` and `fast`, are initialized to point to the head of the linked list. The `slow` pointer will move one step at a time, while the `fast` pointer will move two steps at a time.

3. **While Loop (Cycle Detection)**
	```cpp
	    while(fast && fast->next) {
	```
	The while loop continues as long as the `fast` pointer and its next node are not `nullptr`. This ensures that the loop doesn't run into an invalid memory reference when traversing the list.

4. **Move Slow Pointer**
	```cpp
	        slow = slow->next;
	```
	The `slow` pointer moves one step forward in the list, advancing by one node at a time.

5. **Move Fast Pointer**
	```cpp
	        fast = fast->next->next;
	```
	The `fast` pointer moves two steps forward, advancing by two nodes at a time.

6. **Cycle Detection**
	```cpp
	        if(slow == fast) return true;
	```
	If the `slow` pointer and `fast` pointer meet at the same node, it indicates that a cycle exists in the linked list. The function returns `true`.

7. **Return False (No Cycle)**
	```cpp
	    return false;
	```
	If the `fast` pointer reaches the end of the list (i.e., `fast` or `fast->next` becomes `nullptr`), no cycle is present, so the function returns `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of nodes in the list. The best case occurs when there is no cycle, and the fast pointer reaches the end of the list.
- **Average Case:** O(n), the fast and slow pointers will eventually meet if there is a cycle.
- **Worst Case:** O(n), the worst case is when there is no cycle, and the fast pointer needs to traverse the entire list.

The time complexity is O(n) since each pointer traverses the list at most once.

### Space Complexity 💾
- **Best Case:** O(1), regardless of whether the list has a cycle or not, only two pointers are maintained.
- **Worst Case:** O(1), the space complexity is constant since only two pointers are used.

The space complexity is O(1), as we are not using any additional data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-cycle/description/)

---
{{< youtube 6OrZ4wAy4uE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
