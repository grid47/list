
+++
authors = ["grid47"]
title = "Leetcode 24: Swap Nodes in Pairs"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 24: Swap Nodes in Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/24.webp"
youtube = "o811TZLAWOo"
youtube_upload_date="2020-12-31"
youtube_thumbnail="https://i.ytimg.com/vi/o811TZLAWOo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/24.webp" 
    alt="Two floating nodes gently exchanging places, glowing with subtle motion."
    caption="Solution to LeetCode 24: Swap Nodes in Pairs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the head of a singly linked list. Your task is to swap every two adjacent nodes in the list and return its head. The nodes themselves should be swapped, not just the values.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the head of a singly linked list, where each node has a `val` representing its value.
- **Example:** `Input: head = [1, 2, 3, 4]`
- **Constraints:**
	- 0 <= Node.val <= 100
	- The number of nodes in the list is between 0 and 100.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the modified linked list where every two adjacent nodes have been swapped.
- **Example:** `Output: [2, 1, 4, 3]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to swap every two adjacent nodes while maintaining the rest of the list unchanged.

- 1. Traverse the list with two pointers.
- 2. For each pair of adjacent nodes, swap their positions.
- 3. Ensure the swapped pairs maintain the linkage to the rest of the list.
{{< dots >}}
### Problem Assumptions ✅
- The input list will always have at least zero nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [1, 2, 3, 4]`  \
  **Explanation:** In this example, after swapping every two adjacent nodes, the list becomes [2, 1, 4, 3]. The first two nodes are swapped and the next pair is also swapped.

- **Input:** `Input: head = [1]`  \
  **Explanation:** In this case, there is only one node, so no swap is possible. The output will be the same single node list: [1].

- **Input:** `Input: head = []`  \
  **Explanation:** If the input list is empty, the output should also be empty.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to traverse the list and swap every two adjacent nodes while ensuring the list structure is preserved.

### Initial Thoughts 💭
- This problem requires adjusting the pointers of adjacent nodes without changing their values.
- We can perform this in one pass over the list while keeping track of the previous and next nodes to ensure the linkage is correct after each swap.
{{< dots >}}
### Edge Cases 🌐
- If the input is an empty list, return an empty list.
- The solution should work efficiently for lists with up to 100 nodes.
- If the list contains only one node, no swap is needed and the same list should be returned.
- The solution must preserve the list's structure and ensure no values are modified.
{{< dots >}}
## Code 💻
```cpp
ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    
    
    ListNode* cur = head, *nxt = head->next, *ret = nxt, *prv = NULL;
    
    while(cur != NULL && nxt != NULL) {
        if(prv != NULL) prv->next = nxt;
        prv = cur;            
        cur->next = nxt->next;
        nxt->next = cur;
        cur = cur->next;
        if(cur != NULL) nxt = cur->next;
    }
    return ret;
}
```

This code swaps the nodes of a linked list in pairs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* swapPairs(ListNode* head) {
	```
	This line declares a function named 'swapPairs' that takes a pointer to the head of a linked list as input and returns a pointer to the head of the modified linked list.

2. **Base Case**
	```cpp
	    if(head == NULL || head->next == NULL) return head;
	```
	This line checks if the list is empty or has only one node. In these cases, no swapping is needed, and the original head is returned.

3. **Variable Initialization**
	```cpp
	    ListNode* cur = head, *nxt = head->next, *ret = nxt, *prv = NULL;
	```
	This line initializes four pointers: 'cur' to the current node, 'nxt' to the next node, 'ret' to the new head (which will be the second node), and 'prv' to the previous node (initially NULL).

4. **Loop Iteration**
	```cpp
	    while(cur != NULL && nxt != NULL) {
	```
	This line starts a loop that continues as long as both 'cur' and 'nxt' are not NULL.

5. **Conditional Update**
	```cpp
	        if(prv != NULL) prv->next = nxt;
	```
	If there's a previous node 'prv', its 'next' pointer is updated to point to the current 'nxt' node.

6. **Pointer Update**
	```cpp
	        prv = cur;            
	```
	The 'prv' pointer is updated to point to the current 'cur' node.

7. **Node Manipulation**
	```cpp
	        cur->next = nxt->next;
	```
	The 'next' pointer of the current node 'cur' is updated to point to the node after 'nxt'.

8. **Node Manipulation**
	```cpp
	        nxt->next = cur;
	```
	The 'next' pointer of the 'nxt' node is updated to point to the current 'cur' node, effectively swapping the two nodes.

9. **Pointer Update**
	```cpp
	        cur = cur->next;
	```
	The 'cur' pointer is moved to the next node, which is the original 'nxt' node after the swap.

10. **Pointer Update**
	```cpp
	        if(cur != NULL) nxt = cur->next;
	```
	If 'cur' is not NULL, the 'nxt' pointer is updated to point to the next node after 'cur'.

11. **Return**
	```cpp
	    return ret;
	```
	After the loop, the function returns the new head of the linked list, which is stored in the 'ret' pointer.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Since we process each node once, the time complexity is linear, where n is the number of nodes in the list.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we are only using a few extra pointers for traversal and swapping.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/swap-nodes-in-pairs/description/)

---
{{< youtube o811TZLAWOo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
