
+++
authors = ["grid47"]
title = "Leetcode 109: Convert Sorted List to Binary Search Tree"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 109: Convert Sorted List to Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Divide and Conquer","Tree","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/109.webp"
youtube = "0E8Xxu6LV9o"
youtube_upload_date="2020-11-30"
youtube_thumbnail="https://i.ytimg.com/vi/0E8Xxu6LV9o/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/109.webp" 
    alt="A flowing list of sorted numbers seamlessly transforming into a calm, glowing binary search tree."
    caption="Solution to LeetCode 109: Convert Sorted List to Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the head of a singly linked list where elements are sorted in ascending order, convert it into a height-balanced binary search tree. A height-balanced binary search tree is one where the depth of the two subtrees of every node never differs by more than 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a singly linked list with sorted elements.
- **Example:** `head = [-5, -2, 0, 3, 7, 10, 15]`
- **Constraints:**
	- The number of nodes in the linked list is in the range [0, 20000].
	- -10^5 <= Node.val <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a height-balanced binary search tree represented by its root node.
- **Example:** `[0, -2, 10, -5, 3, 7, null]`
- **Constraints:**
	- The binary search tree must be balanced in height, meaning that the depth of the subtrees at each node should not differ by more than 1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to create a balanced binary search tree from a sorted singly linked list.

- To create the height-balanced BST, recursively pick the middle element of the list as the root, and recursively do the same for the left and right sublists.
{{< dots >}}
### Problem Assumptions ✅
- The input list is sorted in ascending order and contains no duplicates.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: head = [-10, -3, 0, 5, 9]`  \
  **Explanation:** The linked list has 5 elements. The middle element, 0, will be the root. The left part of the list, [-10, -3], will form the left subtree, and the right part of the list, [5, 9], will form the right subtree.

- **Input:** `Input: head = []`  \
  **Explanation:** If the linked list is empty, the resulting binary search tree will also be empty.

{{< dots >}}
## Approach 🚀
The approach involves recursively selecting the middle element from the sorted linked list to ensure the resulting tree is height-balanced. This is done by finding the middle node of the list and making it the root, then applying the same process to the left and right halves.

### Initial Thoughts 💭
- Since the list is already sorted, we can easily identify the middle element to ensure the tree is balanced.
- The recursion ensures that each level of the tree remains balanced by selecting the middle of the list, dividing it into two smaller balanced subtrees.
{{< dots >}}
### Edge Cases 🌐
- If the input linked list is empty, return null as the result.
- The algorithm should efficiently handle large lists with up to 20,000 elements.
- Ensure that the solution handles negative values and large numbers within the specified range.
- Ensure that the function works correctly with both small and large inputs, efficiently processing lists with up to 20,000 elements.
{{< dots >}}
## Code 💻
```cpp
TreeNode* toBST(ListNode* start, ListNode* end) {

    if(start == end) return NULL;

    ListNode* slw = start;
    ListNode* fst = start;

    while(fst != end && fst->next != end) {
        slw = slw->next;
        fst = fst->next->next;
    }

    TreeNode* node = new TreeNode(slw->val);
    node->left = toBST(start, slw);
    node->right = toBST(slw->next, end);
    return node;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(head == NULL) return NULL;
    return toBST(head, NULL);
}
```

This solution converts a sorted linked list to a height-balanced BST using recursion to divide the list into subtrees.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Conditional Function Call**
	```cpp
	TreeNode* toBST(ListNode* start, ListNode* end) {
	```
	Define a recursive helper function to convert list segments into a BST.

2. **Base Case**
	```cpp
	if(start == end) return NULL;
	```
	Base case: If the start equals the end, return NULL as there are no nodes to process.

3. **Pointer Initialization**
	```cpp
	ListNode* slw = start;
	```
	Initialize a slow pointer to find the middle element of the linked list.

4. **Pointer Initialization**
	```cpp
	ListNode* fst = start;
	```
	Initialize a fast pointer to traverse the list twice as fast as the slow pointer.

5. **Loop Iteration**
	```cpp
	while(fst != end && fst->next != end) {
	```
	Move the slow and fast pointers until the fast pointer reaches the end of the segment.

6. **Pointer Movement**
	```cpp
	slw = slw->next;
	```
	Move the slow pointer one step forward.

7. **Pointer Movement**
	```cpp
	fst = fst->next->next;
	```
	Move the fast pointer two steps forward.

8. **Tree Initialization**
	```cpp
	TreeNode* node = new TreeNode(slw->val);
	```
	Create a new tree node with the value of the middle element (slow pointer).

9. **Recursive Call**
	```cpp
	node->left = toBST(start, slw);
	```
	Recursively construct the left subtree from the list segment before the middle element.

10. **Recursive Call**
	```cpp
	node->right = toBST(slw->next, end);
	```
	Recursively construct the right subtree from the list segment after the middle element.

11. **Return Value**
	```cpp
	return node;
	```
	Return the constructed tree node as the root of the current subtree.

12. **Function Declaration**
	```cpp
	TreeNode* sortedListToBST(ListNode* head) {
	```
	Define the main function to convert the sorted list to a BST.

13. **Base Case**
	```cpp
	if(head == NULL) return NULL;
	```
	Handle the edge case where the input list is empty.

14. **Recursive Call**
	```cpp
	return toBST(head, NULL);
	```
	Call the helper function to build the BST, starting with the entire list.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we traverse the entire linked list once to construct the tree.

### Space Complexity 💾
- **Best Case:** O(log n)
- **Worst Case:** O(log n)

The space complexity is O(log n) due to the recursive stack for the tree construction.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/)

---
{{< youtube 0E8Xxu6LV9o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
