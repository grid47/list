
+++
authors = ["grid47"]
title = "Leetcode 876: Middle of the Linked List"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 876: Middle of the Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "-WV-G-QwB38"
youtube_upload_date="2023-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/-WV-G-QwB38/maxresdefault.jpg"
comments = true
+++



---
You are given the head of a singly linked list. Your task is to find and return the middle node of the list. If there are two middle nodes, return the second one.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a singly linked list with nodes containing integer values.
- **Example:** `Input: head = [1, 2, 3, 4, 5]`
- **Constraints:**
	- 1 <= number of nodes <= 100
	- 1 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the middle node of the linked list. If the list has two middle nodes, return the second one.
- **Example:** `Output: [3, 4, 5]`
- **Constraints:**
	- The output should be the list starting from the middle node.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the middle node of the linked list using a two-pointer approach.

- Use two pointers, 'slow' and 'fast'. Initialize both to the head of the list.
- Move the 'slow' pointer one step at a time, and the 'fast' pointer two steps at a time.
- When the 'fast' pointer reaches the end of the list, the 'slow' pointer will be at the middle node.
{{< dots >}}
### Problem Assumptions ✅
- The linked list is non-empty and contains at least one node.
- The linked list may have an even or odd number of nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [1, 2, 3, 4, 5]`  \
  **Explanation:** The list has 5 nodes. The middle node is 3, so the output will be the sublist starting from node 3: [3, 4, 5].

- **Input:** `Input: head = [1, 2, 3, 4, 5, 6]`  \
  **Explanation:** The list has 6 nodes. The two middle nodes are 3 and 4, and since the second middle node should be returned, the output will be the sublist starting from node 4: [4, 5, 6].

{{< dots >}}
## Approach 🚀
We can use the two-pointer technique to efficiently find the middle node of the linked list. The 'slow' pointer will move one step at a time, while the 'fast' pointer will move two steps at a time. When the fast pointer reaches the end, the slow pointer will be at the middle node.

### Initial Thoughts 💭
- The two-pointer technique is optimal for this problem as it allows us to traverse the list in a single pass while keeping track of the middle node.
- The method ensures that we can handle lists with both even and odd numbers of nodes.
{{< dots >}}
### Edge Cases 🌐
- If the list is empty (no nodes), return null or handle as an edge case.
- The solution should efficiently handle up to 100 nodes.
- If the list has only one node, the middle node is that node itself.
- Ensure that the solution works for both even and odd-length lists.
{{< dots >}}
## Code 💻
```cpp
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // if(!fast)
        // return slow->next;
    return slow;
}
```

This code implements an algorithm to find the middle node of a singly linked list using the two-pointer technique. It uses one slow pointer that advances one step at a time, and one fast pointer that advances two steps at a time. When the fast pointer reaches the end, the slow pointer is at the middle.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	ListNode* middleNode(ListNode* head) {
	```
	The function `middleNode` takes a pointer to the head of a singly linked list and returns a pointer to the middle node of the list.

2. **Pointer Initialization**
	```cpp
	    ListNode* slow = head, *fast = head;
	```
	Two pointers, `slow` and `fast`, are initialized to the head of the list. The `slow` pointer moves one node at a time, while the `fast` pointer moves two nodes at a time.

3. **While Loop**
	```cpp
	    while(fast && fast->next) {
	```
	A `while` loop is used to traverse the list. The loop continues as long as the `fast` pointer and the `fast->next` pointer are not null.

4. **Pointer Movement**
	```cpp
	        slow = slow->next;
	```
	The `slow` pointer moves one step forward by advancing to the next node in the list.

5. **Pointer Movement**
	```cpp
	        fast = fast->next->next;
	```
	The `fast` pointer moves two steps forward by advancing to the next node twice, skipping one node in between.

6. **Return Statement**
	```cpp
	    return slow;
	```
	After the loop finishes, the `slow` pointer is returned, which points to the middle node of the list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the list, as we need to traverse the list once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only use a constant amount of extra space for the two pointers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/middle-of-the-linked-list/description/)

---
{{< youtube -WV-G-QwB38 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
