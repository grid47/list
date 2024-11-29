
+++
authors = ["grid47"]
title = "Leetcode 2095: Delete the Middle Node of a Linked List"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2095: Delete the Middle Node of a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gwel0eQ0MhA"
youtube_upload_date="2021-12-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gwel0eQ0MhA/maxresdefault.webp"
comments = true
+++



---
You are given the head of a linked list. Your task is to remove the middle node from the linked list and return the modified list. The middle node is defined as the ⌊n / 2⌋th node, where n is the number of nodes in the list, using 0-based indexing.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a linked list where each node has a value and a pointer to the next node. The linked list has at least one node.
- **Example:** `head = [4, 8, 6, 2, 7, 3]`
- **Constraints:**
	- The number of nodes in the list is in the range [1, 10^5].
	- 1 <= Node.val <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the linked list after removing the middle node. The list should be modified in place.
- **Example:** `Output: [4, 8, 2, 7, 3]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove the middle node from the linked list and return the modified list.

- Use two pointers: one slow and one fast.
- Move the fast pointer two steps at a time and the slow pointer one step at a time.
- When the fast pointer reaches the end, the slow pointer will be at the middle.
- Remove the middle node by linking the previous node of the slow pointer to the next node.
{{< dots >}}
### Problem Assumptions ✅
- The linked list is not empty.
- The values in the list are distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: head = [4, 8, 6, 2, 7, 3]`  \
  **Explanation:** The list has 6 nodes. The middle node is 6 (index 2). After removing it, the list becomes [4, 8, 2, 7, 3].

- **Input:** `Example 2: head = [10, 20, 30, 40]`  \
  **Explanation:** The list has 4 nodes. The middle node is 30 (index 2). After removing it, the list becomes [10, 20, 40].

- **Input:** `Example 3: head = [5, 3]`  \
  **Explanation:** The list has 2 nodes. The middle node is 3 (index 1). After removing it, the list becomes [5].

{{< dots >}}
## Approach 🚀
The key approach to solving this problem involves using two pointers: a slow pointer and a fast pointer. The slow pointer will point to the middle node, while the fast pointer will traverse the list at double the speed to help locate the middle.

### Initial Thoughts 💭
- We need to find the middle node efficiently, ideally with a time complexity of O(n).
- Using a slow and fast pointer technique ensures we can find the middle node in a single pass through the list.
{{< dots >}}
### Edge Cases 🌐
- If the list has only one node, removing the middle node should return an empty list.
- Ensure the solution works for lists with up to 10^5 nodes.
- If there are only two nodes, remove the second node as it is the middle node.
- The input list will always have at least one node.
{{< dots >}}
## Code 💻
```cpp
ListNode* deleteMiddle(ListNode* head) {
    if(!head->next) return nullptr;
    ListNode* slw = head, *fst = head->next->next;
    while(fst && fst->next) {
        fst = fst->next->next;
        slw = slw->next;
    }
    slw->next = slw->next->next;
    return head;
}
```

This function removes the middle node from a linked list. It uses two pointers: a slow pointer and a fast pointer, to find the middle node, and adjusts the links to remove it.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode* deleteMiddle(ListNode* head) {
	```
	Defines the function 'deleteMiddle' that takes a ListNode pointer as input and returns a ListNode pointer.

2. **Base Condition**
	```cpp
	    if(!head->next) return nullptr;
	```
	Checks if the linked list contains only one node. If true, it returns nullptr, as there's no middle node to delete.

3. **Pointer Initialization**
	```cpp
	    ListNode* slw = head, *fst = head->next->next;
	```
	Initializes two pointers: 'slw' (slow pointer) starting at the head, and 'fst' (fast pointer) starting two nodes ahead.

4. **Loop Condition**
	```cpp
	    while(fst && fst->next) {
	```
	The loop continues as long as 'fst' and 'fst->next' are not null, ensuring we don't exceed the bounds of the list.

5. **Pointer Update**
	```cpp
	        fst = fst->next->next;
	```
	Moves the 'fst' pointer two nodes ahead in each iteration of the loop.

6. **Pointer Update**
	```cpp
	        slw = slw->next;
	```
	Moves the 'slw' pointer one node ahead in each iteration of the loop.

7. **Middle Node Removal**
	```cpp
	    slw->next = slw->next->next;
	```
	Removes the middle node by adjusting the 'next' pointer of the 'slw' pointer to skip the middle node.

8. **Return Statement**
	```cpp
	    return head;
	```
	Returns the modified linked list with the middle node removed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we are traversing the linked list once to find and remove the middle node.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we are using only a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/)

---
{{< youtube gwel0eQ0MhA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
