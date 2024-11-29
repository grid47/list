
+++
authors = ["grid47"]
title = "Leetcode 889: Construct Binary Tree from Preorder and Postorder Traversal"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 889: Construct Binary Tree from Preorder and Postorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given two integer arrays representing the preorder and postorder traversals of a binary tree. Your task is to reconstruct the binary tree from these two traversals and return the root node of the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with two integer arrays, preorder and postorder, where preorder is the preorder traversal and postorder is the postorder traversal of a binary tree.
- **Example:** `Input: preorder = [1, 2, 4, 5, 3], postorder = [4, 5, 2, 3, 1]`
- **Constraints:**
	- 1 <= preorder.length <= 30
	- 1 <= preorder[i] <= preorder.length
	- All the values in preorder are unique.
	- postorder.length == preorder.length
	- 1 <= postorder[i] <= postorder.length
	- All the values in postorder are unique.
	- It is guaranteed that preorder and postorder represent the same binary tree.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root node of the reconstructed binary tree.
- **Example:** `Output: [1, 2, 3, 4, 5]`
- **Constraints:**
	- The output should be the root node of the reconstructed tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to use the preorder and postorder traversal information to reconstruct the binary tree. Preorder provides the root first, and postorder gives the root last. We need to identify the left and right subtrees and recursively reconstruct the tree.

- Start with the root node from preorder, which is the first element.
- Use postorder to identify when we reach the root of the current subtree.
- Recursively build the left and right subtrees by using the remaining elements of preorder and postorder, ensuring the structure is consistent with both traversals.
{{< dots >}}
### Problem Assumptions ✅
- The preorder and postorder arrays represent the same binary tree and contain distinct values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: preorder = [1, 2, 4, 5, 3], postorder = [4, 5, 2, 3, 1]`  \
  **Explanation:** In this example, the preorder traversal gives us the root of the tree first, and the postorder traversal tells us the root of the tree last. From the preorder traversal, we start with node 1 as the root. The left and right subtrees are identified by examining the first and last few elements of the arrays, reconstructing the tree recursively.

- **Input:** `Input: preorder = [1], postorder = [1]`  \
  **Explanation:** In this case, the tree consists of just one node, 1, which is both the root and the only node in the tree.

{{< dots >}}
## Approach 🚀
The problem requires reconstructing the binary tree from the preorder and postorder traversals. We need to use the information in the traversals to identify the root, left, and right subtrees recursively.

### Initial Thoughts 💭
- Preorder traversal provides the root first, which helps in identifying the root of the tree at each level.
- Postorder traversal provides the root last, allowing us to identify the boundaries of the left and right subtrees.
- We can use recursion to process each subtree by maintaining the preorder and postorder arrays, adjusting the indices as we recursively construct the tree.
{{< dots >}}
### Edge Cases 🌐
- If both preorder and postorder are empty, the tree is empty, and we return null.
- The solution should efficiently handle the case where the length of the input arrays is 30.
- If the tree consists of only one node, both preorder and postorder will have a single element.
- Ensure that the solution works for arrays with maximum size of 30 and handles recursion efficiently.
{{< dots >}}
## Code 💻
```cpp
int preIdx = 0, postIdx = 0;
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    TreeNode* root = new TreeNode(preorder[preIdx++]);

    if(root->val  != postorder[postIdx])
        root->left = constructFromPrePost(preorder, postorder);

    if(root->val  != postorder[postIdx])
        root->right = constructFromPrePost(preorder, postorder);

    postIdx++;
    return root;
}
```

This is the full implementation of the algorithm to construct a binary tree from preorder and postorder traversal arrays. The recursive function builds the tree by checking the root value and its corresponding children based on preorder and postorder lists.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int preIdx = 0, postIdx = 0;
	```
	Initialize two index variables, preIdx and postIdx, to traverse the preorder and postorder arrays respectively.

2. **Function Definition**
	```cpp
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
	```
	Define the recursive function to construct the binary tree from preorder and postorder traversals.

3. **Node Creation**
	```cpp
	    TreeNode* root = new TreeNode(preorder[preIdx++]);
	```
	Create a new tree node with the current value from the preorder array and increment the preIdx to move to the next element.

4. **Condition Check**
	```cpp
	    if(root->val  != postorder[postIdx])
	```
	Check if the current node's value does not match the value in the postorder array. If it doesn't, the left child is not fully constructed.

5. **Recursive Left Child Construction**
	```cpp
	        root->left = constructFromPrePost(preorder, postorder);
	```
	Recursively construct the left subtree if the root's value doesn't match the postorder value at postIdx.

6. **Condition Check**
	```cpp
	    if(root->val  != postorder[postIdx])
	```
	Check again for the root's value not matching the postorder array. If it still doesn't match, the right child is not fully constructed.

7. **Recursive Right Child Construction**
	```cpp
	        root->right = constructFromPrePost(preorder, postorder);
	```
	Recursively construct the right subtree if the root's value still doesn't match the postorder value at postIdx.

8. **Postorder Index Update**
	```cpp
	    postIdx++;
	```
	Increment the postIdx to move to the next element in the postorder traversal after constructing both left and right subtrees.

9. **Return Root**
	```cpp
	    return root;
	```
	Return the root node, which now has its left and right subtrees properly linked.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), where n is the number of nodes in the tree, as we visit each node once during the recursion.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursion stack and the space needed to store the tree structure.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
