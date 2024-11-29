
+++
authors = ["grid47"]
title = "Leetcode 92: Reverse Linked List II"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 92: Reverse Linked List II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/92.webp"
youtube = "RF_M9tX4Eag"
youtube_upload_date="2021-10-01"
youtube_thumbnail="https://i.ytimg.com/vi/RF_M9tX4Eag/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/92.webp" 
    alt="A linked list gently reversing, glowing softly with each node that changes position."
    caption="Solution to LeetCode 92: Reverse Linked List II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the head of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the linked list starting at position `left` and ending at position `right`. Return the modified linked list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The function receives the head of a singly linked list and two integers `left` and `right` representing the positions in the list to reverse.
- **Example:** `Input: head = [7,9,11,5,2], left = 3, right = 5`
- **Constraints:**
	- The number of nodes in the list is n.
	- 1 <= n <= 500
	- -500 <= Node.val <= 500
	- 1 <= left <= right <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the modified singly linked list after reversing the specified section.
- **Example:** `Output: [7,9,2,5,11]`
- **Constraints:**
	- The output list retains all nodes from the original list.
	- The reversed portion is accurately modified while the rest remains untouched.

{{< dots >}}
### Core Logic 🔍
**Goal:** Reverse the nodes of a singly linked list between positions `left` and `right` in a single traversal.

- Create a dummy node pointing to the head of the list.
- Traverse to the node immediately before position `left`.
- Perform in-place node re-linking to reverse the sublist between `left` and `right`.
- Reconnect the reversed sublist to the remaining parts of the list.
{{< dots >}}
### Problem Assumptions ✅
- The input list is non-circular and contains valid node values.
- `left` and `right` are always within valid bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [3,6,1,8,5], left = 2, right = 4`  \
  **Explanation:** Reverse the sublist from position 2 to 4. Resulting list is [3,8,1,6,5].

- **Input:** `Input: head = [10], left = 1, right = 1`  \
  **Explanation:** Since the list contains a single node and `left == right`, the list remains [10].

{{< dots >}}
## Approach 🚀
Reverse a sublist in the linked list using in-place re-linking. Maintain pointers to manage the reversed sublist and the unaffected portions efficiently.

### Initial Thoughts 💭
- Reversing a sublist can be done by adjusting the next pointers of the nodes within the range.
- A dummy node helps handle edge cases cleanly, such as reversing from the head of the list.
- Minimize traversal by reversing the sublist in-place.
- Optimize space usage to O(1) by not using additional data structures.
{{< dots >}}
### Edge Cases 🌐
- Input list is NULL.
- List has 500 nodes and requires reversing a large sublist.
- Input values at the boundary of valid ranges, e.g., `left = 1`, `right = n`.
- Ensure nodes outside the reversal range remain unmodified.
{{< dots >}}
## Code 💻
```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    for (int i = 0; i < left - 1; ++i) {
        prev = prev->next;
    }

    ListNode* curr = prev->next;
    ListNode* next = curr->next;

    for (int i = 0; i < right - left; ++i) {
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = curr->next;
    }

    return dummy->next;
}
```

This code reverses a linked list between the given positions `left` and `right`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* reverseBetween(ListNode* head, int left, int right) {
	```
	Declares a function `reverseBetween` that takes a linked list `head`, a starting position `left`, and an ending position `right` as input and returns the modified linked list.

2. **Edge Case Check**
	```cpp
	    if (!head) return head;
	```
	Checks if the input linked list is empty. If so, returns the head directly.

3. **Dummy Node Initialization**
	```cpp
	    ListNode* dummy = new ListNode(0);
	```
	Creates a dummy node to simplify the reversal process, especially when reversing from the beginning of the list.

4. **Pointer Assignment**
	```cpp
	    dummy->next = head;
	```
	Sets the `next` pointer of the dummy node to the head of the original linked list.

5. **Pointer Initialization**
	```cpp
	    ListNode* prev = dummy;
	```
	Initializes a `prev` pointer to the dummy node, which will be used to track the node before the reversal range.

6. **Loop Iteration, Pointer Update**
	```cpp
	    for (int i = 0; i < left - 1; ++i) {
	        prev = prev->next;
	    }
	```
	Iterates `left - 1` times to move the `prev` pointer to the node just before the start of the reversal range.

7. **Pointer Initialization**
	```cpp
	    ListNode* curr = prev->next;
	```
	Initializes a `curr` pointer to the first node in the reversal range.

8. **Pointer Initialization**
	```cpp
	    ListNode* next = curr->next;
	```
	Initializes a `next` pointer to the node after `curr`, which will be used to temporarily store the next node during the reversal process.

9. **Loop Iteration, Pointer Manipulation**
	```cpp
	    for (int i = 0; i < right - left; ++i) {
	```
	Iterates `right - left` times to reverse the nodes in the specified range.

10. **Pointer Manipulation**
	```cpp
	        curr->next = next->next;
	```
	Sets the `next` pointer of the current node `curr` to the node after the next node.

11. **Pointer Manipulation**
	```cpp
	        next->next = prev->next;
	```
	Sets the `next` pointer of the next node `next` to the node that `prev` currently points to, effectively reversing the link.

12. **Pointer Manipulation**
	```cpp
	        prev->next = next;
	```
	Sets the `next` pointer of the `prev` node to the current `next` node, linking it to the reversed portion.

13. **Pointer Update**
	```cpp
	        next = curr->next;
	```
	Moves the `next` pointer to the next node to be reversed in the next iteration.

14. **Return**
	```cpp
	    return dummy->next;
	```
	Returns the head of the modified linked list, which is the `next` pointer of the dummy node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The entire list may need to be traversed in the worst case, where `right = n`.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses constant space for pointers and variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-linked-list-ii/description/)

---
{{< youtube RF_M9tX4Eag >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
