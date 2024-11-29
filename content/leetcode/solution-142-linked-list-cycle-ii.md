
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
comments = true
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
Given the head of a linked list, find the node where the cycle begins. If no cycle exists, return null. The list may contain a cycle, which occurs if a node can be revisited by following the 'next' pointers continuously.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a linked list and an index 'pos' where the tail node connects. If 'pos' is -1, there is no cycle.
- **Example:** `Input: head = [5, 3, 9, 4], pos = 2`
- **Constraints:**
	- The number of nodes in the list is between 0 and 10^4.
	- Node values range between -10^5 and 10^5.
	- 'pos' is either -1 or a valid index within the list.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the node where the cycle begins, or null if no cycle is detected.
- **Example:** `Output: tail connects to node index 2`
- **Constraints:**
	- The output is the node where the cycle begins, or null if no cycle exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to detect the node where the cycle begins in the linked list.

- 1. Use two pointers, 'slow' and 'fast', which start at the head of the list.
- 2. Move the slow pointer one step and the fast pointer two steps at a time.
- 3. If a cycle exists, slow and fast pointers will meet at some point.
- 4. Once a cycle is detected, reset one pointer to the head and keep the other at the meeting point.
- 5. Move both pointers one step at a time until they meet again. This is the start of the cycle.
{{< dots >}}
### Problem Assumptions ✅
- The linked list may contain a cycle or it may be acyclic.
- Nodes may contain integer values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [5, 3, 9, 4], pos = 2`  \
  **Explanation:** In this example, the linked list has a cycle where the tail connects to the 2nd node (index 2).

{{< dots >}}
## Approach 🚀
The solution uses Floyd's Cycle-Finding Algorithm (Tortoise and Hare) to detect the cycle and then find the starting node of the cycle.

### Initial Thoughts 💭
- The problem can be solved by detecting the cycle first and then finding the cycle's start node.
- By using two pointers, one moving faster than the other, we can detect the cycle in O(n) time. Once the cycle is detected, finding the start node requires another O(n) pass.
{{< dots >}}
### Edge Cases 🌐
- An empty linked list should return null since there is no cycle.
- The algorithm should efficiently handle large lists with up to 10^4 nodes.
- When the cycle begins at the very first node or is self-referential (the last node points to itself).
- The solution should run in linear time (O(n)) and use constant space (O(1)).
{{< dots >}}
## Code 💻
```cpp
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
```

This function detects the cycle in a linked list using Floyd's Cycle Detection Algorithm. It uses the 'fast' and 'slow' pointers to identify the cycle and returns the node where the cycle begins.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode *detectCycle(ListNode *head) {
	```
	This defines the `detectCycle` function that takes a pointer `head` to the start of the linked list and returns a pointer to the node where the cycle begins, or `NULL` if no cycle exists.

2. **Base Case Check**
	```cpp
	    if(head == NULL) return NULL;
	```
	If the list is empty (i.e., `head` is `NULL`), the function immediately returns `NULL`, as there can be no cycle in an empty list.

3. **Pointer Initialization**
	```cpp
	    ListNode *fast = head, *slow= head;
	```
	Two pointers, `fast` and `slow`, are initialized to the head of the linked list. `fast` moves two steps at a time and `slow` moves one step at a time.

4. **Cycle Detection Loop**
	```cpp
	    while(fast && fast->next) {
	```
	This loop continues as long as `fast` and `fast->next` are valid, ensuring we do not run into null references while traversing the list.

5. **Move Slow Pointer**
	```cpp
	        slow = slow->next;
	```
	The `slow` pointer moves one step forward in the linked list.

6. **Move Fast Pointer**
	```cpp
	        fast = fast->next->next;
	```
	The `fast` pointer moves two steps forward in the list.

7. **Cycle Detection Check**
	```cpp
	        if(fast == slow) break;
	```
	If the `fast` and `slow` pointers meet at the same node, a cycle is detected, and the loop breaks.

8. **No Cycle Check**
	```cpp
	    if(!(fast && fast->next)) return NULL;
	```
	If the `fast` pointer reaches the end of the list (`fast` or `fast->next` is `NULL`), no cycle exists, and the function returns `NULL`.

9. **Second Loop for Cycle Start**
	```cpp
	    while (head != slow) {
	```
	This loop moves both `head` and `slow` pointers one step at a time to find the node where the cycle begins.

10. **Move Head Pointer**
	```cpp
	        head = head->next;
	```
	Moves the `head` pointer one step forward.

11. **Move Slow Pointer**
	```cpp
	        slow = slow->next;
	```
	Moves the `slow` pointer one step forward.

12. **Return Cycle Start Node**
	```cpp
	    return slow;
	```
	At this point, both the `head` and `slow` pointers are at the node where the cycle starts, and this node is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), when the cycle is detected after moving through most of the list.
- **Average Case:** O(n), the slow and fast pointers will meet at some point if a cycle exists.
- **Worst Case:** O(n), in the worst case, the fast pointer will traverse the entire list.

The time complexity is O(n) because each pointer moves at most n steps.

### Space Complexity 💾
- **Best Case:** O(1), since no extra space is used.
- **Worst Case:** O(1), as the solution only uses two pointers.

The space complexity is O(1), as only two pointers are used for cycle detection.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-cycle-ii/description/)

---
{{< youtube Yn5xqbK95Uw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
