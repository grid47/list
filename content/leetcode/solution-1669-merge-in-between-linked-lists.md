
+++
authors = ["grid47"]
title = "Leetcode 1669: Merge In Between Linked Lists"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1669: Merge In Between Linked Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pI775VutBxg"
youtube_upload_date="2024-03-20"
youtube_thumbnail="https://i.ytimg.com/vi/pI775VutBxg/maxresdefault.jpg"
comments = true
+++



---
You are given two linked lists: `list1` and `list2` with sizes `n` and `m` respectively. The task is to remove the nodes from position `a` to position `b` in `list1` and replace them with `list2`. Return the head of the modified list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two linked lists, `list1` and `list2`, along with indices `a` and `b` which define the range of nodes to be removed from `list1`.
- **Example:** `list1 = [5,3,9,7,2,8], a = 2, b = 3, list2 = [100,200,300]`
- **Constraints:**
	- 3 <= list1.length <= 104
	- 1 <= a <= b < list1.length - 1
	- 1 <= list2.length <= 104

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the modified list after replacing the specified nodes in `list1` with `list2`.
- **Example:** `[5,3,100,200,300,2,8]`
- **Constraints:**
	- The returned list should reflect the changes made.

{{< dots >}}
### Core Logic 🔍
**Goal:** To modify `list1` by removing the specified nodes and inserting `list2` in their place.

- Identify the nodes in `list1` at positions `a` and `b`.
- Remove the nodes between positions `a` and `b` in `list1`.
- Link the previous part of `list1` to the first node of `list2`.
- Link the last node of `list2` to the remainder of `list1`.
{{< dots >}}
### Problem Assumptions ✅
- The linked list is non-empty, and the indices `a` and `b` are within the valid range.
{{< dots >}}
## Examples 🧩
- **Input:** `list1 = [5,3,9,7,2,8], a = 2, b = 3, list2 = [100,200,300]`  \
  **Explanation:** We remove the nodes at positions 2 and 3 (`9` and `7`) and insert the list `[100,200,300]` in their place.

- **Input:** `list1 = [0,2,4,6,8,10], a = 1, b = 3, list2 = [500,600,700]`  \
  **Explanation:** The nodes at positions 1, 2, and 3 (`2`, `4`, and `6`) are removed, and `[500,600,700]` is inserted in their place.

{{< dots >}}
## Approach 🚀
The problem can be solved by breaking the list into three parts: the part before the range to be removed, the nodes in the range, and the part after the range. We will then link the parts accordingly.

### Initial Thoughts 💭
- We need to efficiently modify the list by handling pointers between nodes.
- The key task is to update the pointers to remove the middle section and insert the new list in its place.
{{< dots >}}
### Edge Cases 🌐
- There are no cases with empty input lists as per the problem constraints.
- The solution must handle lists of maximum length efficiently.
- Ensure that all list positions `a` and `b` are valid and within bounds.
- There are no edge cases with negative indices or lists of length zero as input.
{{< dots >}}
## Code 💻
```cpp
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* f = list1, *s = list1;
    for(int i = 0; i < a-1; i++) f = f->next;
    for(int i = 0; i < b; i++) s = s->next;
    f->next = list2;
    while(list2->next) list2 = list2->next;
    list2->next = s->next;
    return list1;
}
```

This function merges two linked lists by inserting one list (`list2`) into another (`list1`) at a specific position, defined by the indices `a` and `b`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
	```
	Defines the function `mergeInBetween`, which takes two linked lists (`list1` and `list2`) and merges `list2` into `list1` starting from index `a` and ending at index `b`.

2. **Pointer Initialization**
	```cpp
	    ListNode* f = list1, *s = list1;
	```
	Initializes two pointers `f` and `s`, both starting at the head of `list1`. `f` will move to the position just before `a` and `s` will move to position `b`.

3. **Loop for 'f' Pointer**
	```cpp
	    for(int i = 0; i < a-1; i++) f = f->next;
	```
	Moves pointer `f` to the node just before the insertion point `a`.

4. **Loop for 's' Pointer**
	```cpp
	    for(int i = 0; i < b; i++) s = s->next;
	```
	Moves pointer `s` to the node at position `b` in `list1`, the end of the section where `list2` will be inserted.

5. **Linking List2**
	```cpp
	    f->next = list2;
	```
	Links the node just before position `a` (pointed to by `f`) to the head of `list2`, starting the insertion process.

6. **Traversal of List2**
	```cpp
	    while(list2->next) list2 = list2->next;
	```
	Traverses to the last node of `list2` so that the last node can be connected to the node after `b`.

7. **Final Linking**
	```cpp
	    list2->next = s->next;
	```
	Links the last node of `list2` to the node after position `b` in `list1`, effectively completing the merge.

8. **Return Updated List**
	```cpp
	    return list1;
	```
	Returns the head of the updated `list1`, which now contains the merged result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is linear, where `n` is the length of `list1` and `m` is the length of `list2`.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we are modifying the list in place without needing additional data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-in-between-linked-lists/description/)

---
{{< youtube pI775VutBxg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
