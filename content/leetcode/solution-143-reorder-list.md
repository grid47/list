
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
comments = true
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
You are given the head of a singly linked list. The goal is to reorder the list such that the nodes are arranged as follows: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ..., without modifying the values of the nodes. Only the structure of the list can be changed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a singly linked list with integer values. The linked list is given by its head node.
- **Example:** `Input: head = [10, 20, 30, 40]`
- **Constraints:**
	- The number of nodes in the list is in the range [1, 5 * 10^4].
	- 1 <= Node.val <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the reordered linked list where nodes are arranged as L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
- **Example:** `Output: [10, 40, 20, 30]`
- **Constraints:**
	- The output should be a singly linked list with the nodes rearranged as described.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reorder the linked list as per the given structure without modifying the node values.

- 1. Find the middle of the list using the slow and fast pointer approach.
- 2. Reverse the second half of the list.
- 3. Merge the first half and the reversed second half by alternating nodes from each half.
{{< dots >}}
### Problem Assumptions ✅
- The input list is non-empty and contains valid integers.
- The list is not cyclic.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [10, 20, 30, 40]`  \
  **Explanation:** In this example, the list is reordered as [10, 40, 20, 30], where the first node is followed by the last node, then the second node, followed by the second last node, and so on.

{{< dots >}}
## Approach 🚀
The solution involves three main steps: finding the middle of the list, reversing the second half, and merging the two halves.

### Initial Thoughts 💭
- The problem requires rearranging nodes without modifying their values.
- A two-pointer approach can help find the middle of the list. After that, reversing the second half allows us to merge both halves in the required order.
{{< dots >}}
### Edge Cases 🌐
- If the input list contains only one node, the list remains unchanged.
- The algorithm should efficiently handle lists with up to 50,000 nodes.
- The list may contain nodes with varying values, but the algorithm should not modify their values, only their positions.
- The solution must use linear time and constant space.
{{< dots >}}
## Code 💻
```cpp
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
```

This function reorders a linked list to the specific pattern: first element, last element, second element, second last element, and so on. It uses the slow and fast pointer technique to find the middle, reverses the second half of the list, and then merges the two halves.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	void reorderList(ListNode* head) {
	```
	This defines the `reorderList` function, which reorders the nodes of a linked list in a specific pattern by modifying the list in-place.

2. **Pointer Initialization**
	```cpp
	    ListNode* fast = head, *slow = head;
	```
	Two pointers, `fast` and `slow`, are initialized at the head of the list. `fast` moves two steps at a time, and `slow` moves one step at a time.

3. **Find Middle**
	```cpp
	    while(fast->next && fast->next->next) {
	```
	This loop runs until the `fast` pointer reaches the end of the list. It helps in finding the middle of the linked list using the slow and fast pointer technique.

4. **Move Slow Pointer**
	```cpp
	        slow = slow->next;
	```
	The `slow` pointer moves one step at a time toward the middle of the list.

5. **Move Fast Pointer**
	```cpp
	        fast = fast->next->next;
	```
	The `fast` pointer moves two steps at a time, so when it reaches the end, the `slow` pointer will be at the middle of the list.

6. **Middle Node**
	```cpp
	    ListNode* mid = slow->next;
	```
	After finding the middle of the list, the `mid` pointer is initialized to the node right after the `slow` pointer.

7. **Break First Half**
	```cpp
	    slow->next = NULL;
	```
	Breaks the list into two halves by setting `slow->next` to `NULL`, thus isolating the first half of the list.

8. **Pointer Initialization for Reversal**
	```cpp
	    ListNode* next, *prev = NULL;
	```
	Two pointers, `prev` and `next`, are initialized. `prev` is used for reversing the second half of the list.

9. **Reverse Second Half**
	```cpp
	    while(mid) {
	```
	This loop reverses the second half of the list by iterating over the nodes starting from `mid`.

10. **Save Next Node**
	```cpp
	        next = mid->next;
	```
	Saves the next node in the `next` pointer to avoid losing the reference during the reversal.

11. **Reverse Link**
	```cpp
	        mid->next = prev;
	```
	Reverses the `mid` node's `next` pointer to point to the previous node, effectively reversing the list.

12. **Update Previous Pointer**
	```cpp
	        prev = mid;
	```
	Moves the `prev` pointer one step forward to the current node (`mid`), preparing it for the next iteration.

13. **Move Mid Pointer**
	```cpp
	        mid = next;
	```
	Moves the `mid` pointer to the next node in the original list.

14. **Pointer Initialization for Merging**
	```cpp
	    ListNode* l1 = head, *l2 = prev;
	```
	Initializes two pointers, `l1` pointing to the head of the first half, and `l2` pointing to the head of the reversed second half.

15. **Merge Two Halves**
	```cpp
	    while(l1 && l2) {
	```
	This loop merges the two halves by alternating nodes from `l1` and `l2`.

16. **Save Next Node in First Half**
	```cpp
	        ListNode* tmp1 = l1->next;
	```
	Saves the next node of `l1` in `tmp1` to prevent losing the reference during the merge.

17. **Connect First Half to Second Half**
	```cpp
	        l1->next = l2;
	```
	Connects the current node of the first half (`l1`) to the current node of the second half (`l2`).

18. **Save Next Node in Second Half**
	```cpp
	        ListNode* tmp2 = l2->next;
	```
	Saves the next node of `l2` in `tmp2` to ensure the merge can continue.

19. **Connect Second Half to First Half**
	```cpp
	        l2->next = tmp1;
	```
	Connects the current node of the second half (`l2`) to the next node of the first half (`tmp1`).

20. **Move to Next Nodes**
	```cpp
	        l1 = tmp1;
	```
	Moves the `l1` pointer to the next node in the first half.

21. **Move to Next Nodes**
	```cpp
	        l2 = tmp2;
	```
	Moves the `l2` pointer to the next node in the second half.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), when the list is reordered by following the standard procedure.
- **Average Case:** O(n), the list will always require a full traversal for reordering.
- **Worst Case:** O(n), the solution works in linear time in all cases.

The time complexity is O(n) because we traverse the list multiple times, but each traversal is linear.

### Space Complexity 💾
- **Best Case:** O(1), the space complexity remains constant.
- **Worst Case:** O(1), since only a few pointers are used.

The space complexity is O(1) because no extra space is used apart from a few pointers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reorder-list/description/)

---
{{< youtube i3HU4Ur3-uM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
