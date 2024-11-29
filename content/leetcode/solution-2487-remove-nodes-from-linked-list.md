
+++
authors = ["grid47"]
title = "Leetcode 2487: Remove Nodes From Linked List"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2487: Remove Nodes From Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Stack","Recursion","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "y783sRTezDg"
youtube_upload_date="2024-05-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/y783sRTezDg/maxresdefault.webp"
comments = true
+++



---
You are given the head of a linked list. Your task is to remove every node that has a node with a greater value to its right. The modified linked list should be returned after the removal of such nodes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the head of a singly linked list, where each node contains a single integer value.
- **Example:** `head = [4, 3, 9, 1, 7]`
- **Constraints:**
	- 1 <= Number of nodes <= 10^5
	- 1 <= Node.val <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the head of the modified linked list after removing the nodes that have a greater value node to the right.
- **Example:** `Output: [9, 7]`
- **Constraints:**
	- The returned linked list will not have any node with a value smaller than any node to its right.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to iterate through the list and identify nodes whose values are smaller than any of the nodes that appear to their right. Remove those nodes.

- 1. Start from the head of the list and recursively process the right part of the list.
- 2. For each node, compare its value with the maximum value found in the remaining list.
- 3. If the node's value is less than the maximum value on its right, remove the node. Otherwise, keep the node in the list.
{{< dots >}}
### Problem Assumptions ✅
- The input list is a valid singly linked list.
- All nodes are distinct or may have duplicate values, but values are within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `head = [4, 3, 9, 1, 7]`  \
  **Explanation:** In this case, the nodes with values 4, 3, and 1 should be removed. 9 and 7 remain because no larger nodes exist to the right of these.

- **Input:** `head = [10, 20, 30, 40]`  \
  **Explanation:** No nodes need to be removed in this case as each node is larger than all nodes to its right.

- **Input:** `head = [1, 2, 3, 2, 1]`  \
  **Explanation:** In this case, only the node with value 1 should remain as the others have greater nodes to their right.

{{< dots >}}
## Approach 🚀
We use a recursive approach to solve this problem. As we traverse the list from right to left, we compare the current node with the maximum value on the right side. Nodes that are smaller than the maximum are removed.

### Initial Thoughts 💭
- We need to efficiently remove nodes that have a greater value node to their right.
- We can traverse the list recursively to achieve this.
- By processing the list from the rightmost node to the left, we can ensure that we always compare the current node with the maximum value on its right.
{{< dots >}}
### Edge Cases 🌐
- If the linked list contains only one node, return the list as is.
- Ensure the solution runs efficiently with input sizes of up to 10^5 nodes.
- If all nodes have the same value, no nodes should be removed.
- Handle lists with large input sizes efficiently, with a linear time complexity.
{{< dots >}}
## Code 💻
```cpp
ListNode* removeNodes(ListNode* head) {
    if(head == NULL) return NULL;
    head->next = removeNodes(head->next);
    return head->next != NULL && head->val < head->next->val ? head->next: head;
}
```

This function removes nodes from a linked list where the value of the node is smaller than the value of the next node, recursively processing the list from the end to the beginning.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	ListNode* removeNodes(ListNode* head) {
	```
	This line declares the function `removeNodes` which takes a pointer to a `ListNode` (`head`) as input and returns a pointer to a `ListNode` after potentially removing certain nodes.

2. **Base Case Check**
	```cpp
	    if(head == NULL) return NULL;
	```
	This is the base case of the recursion. If the current node is NULL (i.e., the end of the list is reached), the function returns NULL.

3. **Recursive Call**
	```cpp
	    head->next = removeNodes(head->next);
	```
	This line recursively calls the `removeNodes` function on the next node (`head->next`), processing the entire list from end to start.

4. **Condition for Node Removal**
	```cpp
	    return head->next != NULL && head->val < head->next->val ? head->next: head;
	```
	After the recursive call, this line checks if the current node's value is smaller than the next node's value. If it is, the current node is skipped, and the next node becomes the new head. Otherwise, the current node is retained.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes in the linked list. We traverse the list once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to recursion stack space in the worst case. In the best case, no extra space is needed.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-nodes-from-linked-list/description/)

---
{{< youtube y783sRTezDg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
