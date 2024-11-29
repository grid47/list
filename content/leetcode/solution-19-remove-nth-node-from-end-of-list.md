
+++
authors = ["grid47"]
title = "Leetcode 19: Remove Nth Node From End of List"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 19: Remove Nth Node From End of List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/19.webp"
youtube = "XVuQxVej6y8"
youtube_upload_date="2020-12-29"
youtube_thumbnail="https://i.ytimg.com/vi/XVuQxVej6y8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/19.webp" 
    alt="A single node being gently removed from a glowing chain, leaving a calm, uninterrupted flow."
    caption="Solution to LeetCode 19: Remove Nth Node From End of List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the head of a singly linked list. Your task is to remove the nth node from the end of the list and return the updated list.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a singly linked list and an integer n.
- **Example:** `head = [1, 2, 3, 4, 5], n = 2`
- **Constraints:**
	- 1 <= sz <= 30
	- 0 <= Node.val <= 100
	- 1 <= n <= sz

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the updated list after removing the nth node from the end.
- **Example:** `[1, 2, 3, 5]`
- **Constraints:**
	- The list will always have at least n nodes.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove the nth node from the end of the list by first calculating the size of the list and then locating the node to remove.

- Calculate the length of the linked list.
- Determine the target node to remove (n-th node from the end).
- Traverse the list again to find the node just before the target node.
- Update the next pointer of the previous node to skip the target node.
{{< dots >}}
### Problem Assumptions ✅
- The list is non-empty and contains at least one node.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [1, 2, 3, 4, 5], n = 2`  \
  **Explanation:** The list is [1, 2, 3, 4, 5]. Removing the 2nd node from the end (node 4) results in [1, 2, 3, 5].

{{< dots >}}
## Approach 🚀
The approach involves first calculating the length of the list, then finding the target node and updating the list pointers to remove the desired node.

### Initial Thoughts 💭
- The key observation is that once we know the length of the list, we can easily identify the node to remove.
- First, count the total number of nodes, then subtract n to get the target node's index from the start of the list. Traverse the list again to remove that node.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one node in the linked list.
- The list size is small, so performance with large inputs is not a concern.
- If the list contains only one node, removing it will leave the list empty.
- The list will always contain at least n nodes.
{{< dots >}}
## Code 💻
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* node = head;
    int sz = 0;
    while(node) {
        node = node->next;
        sz++;
    }
    node = head;
    int tgt = sz - n;
    if(sz == n) return head->next;
    for(int i = 0; i < tgt-1; i++)
        node = node->next;
    if(node->next)
    node->next = node->next->next;
    
    return head;
}
```

This code implements the `removeNthFromEnd` function, which removes the nth node from the end of a linked list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* removeNthFromEnd(ListNode* head, int n) {
	```
	Declare the `removeNthFromEnd` function, which takes a pointer to the head of a linked list `head` and an integer `n` as input and returns a pointer to the head of the modified linked list.

2. **Variable Initialization**
	```cpp
	    ListNode* node = head;
	```
	Initialize a pointer `node` to the head of the linked list.

3. **Variable Initialization**
	```cpp
	    int sz = 0;
	```
	Initialize a variable `sz` to store the size of the linked list.

4. **Loop Iteration**
	```cpp
	    while(node) {
	```
	Start a loop to iterate through the linked list.

5. **Pointer Manipulation**
	```cpp
	        node = node->next;
	```
	Move the `node` pointer to the next node in the linked list.

6. **Increment**
	```cpp
	        sz++;
	```
	Increment the `sz` variable to count the number of nodes.

7. **Variable Initialization**
	```cpp
	    node = head;
	```
	Reset the `node` pointer to the head of the linked list.

8. **Calculations**
	```cpp
	    int tgt = sz - n;
	```
	Calculate the target index `tgt` of the node to be removed, which is the size of the list minus `n`.

9. **Conditional Return**
	```cpp
	    if(sz == n) return head->next;
	```
	If `n` is equal to the size of the list, it means we need to remove the head node. Return the next node as the new head.

10. **Loop Iteration**
	```cpp
	    for(int i = 0; i < tgt-1; i++)
	```
	Iterate `tgt-1` times to reach the node before the node to be removed.

11. **Pointer Manipulation**
	```cpp
	        node = node->next;
	```
	Move the `node` pointer to the next node in each iteration.

12. **Conditional Update**
	```cpp
	    if(node->next)
	```
	Check if the next node exists.

13. **Pointer Manipulation**
	```cpp
	    node->next = node->next->next;
	```
	If the next node exists, skip it by setting the `next` pointer of the current node to the node after the next node.

14. **Return Value**
	```cpp
	    return head;
	```
	Return the head of the modified linked list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, the solution involves two passes through the linked list, resulting in linear time complexity.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few extra variables for tracking the list size and current node.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

---
{{< youtube XVuQxVej6y8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
