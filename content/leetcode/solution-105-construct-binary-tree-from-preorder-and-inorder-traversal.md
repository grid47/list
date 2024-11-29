
+++
authors = ["grid47"]
title = "Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/105.webp"
youtube = "GeltTz3Z1rw"
youtube_upload_date="2020-01-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/GeltTz3Z1rw/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/105.webp" 
    alt="A tree gently forming from two intertwining paths of glowing nodes, one representing preorder, the other inorder."
    caption="Solution to LeetCode 105: Construct Binary Tree from Preorder and Inorder Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two integer arrays, `preorder` and `inorder`, representing the preorder and inorder traversals of a binary tree, your task is to reconstruct and return the binary tree. The values in the arrays are unique, and the preorder traversal provides the sequence in which nodes are visited before their children, while the inorder traversal provides the order in which nodes are visited between their children.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: `preorder` and `inorder`. `preorder` represents the preorder traversal of a binary tree, and `inorder` represents the inorder traversal of the same tree.
- **Example:** `preorder = [4,2,1,3,6,5], inorder = [1,2,3,4,5,6]`
- **Constraints:**
	- 1 <= preorder.length <= 3000
	- inorder.length == preorder.length
	- -3000 <= preorder[i], inorder[i] <= 3000
	- preorder and inorder consist of unique values.
	- Each value of inorder also appears in preorder.
	- preorder is guaranteed to be the preorder traversal of the tree.
	- inorder is guaranteed to be the inorder traversal of the tree.

{{< dots >}}
### Output Specifications 📤
- **Output:** You should return the root node of the binary tree constructed from the given preorder and inorder traversal arrays.
- **Example:** `Output: [4,2,6,1,3,5]`
- **Constraints:**
	- The output should be the root node of the reconstructed binary tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to rebuild the binary tree by leveraging the properties of preorder and inorder traversals. In preorder, the first element is always the root, and the elements before it in inorder represent the left subtree, while the elements after it represent the right subtree.

- First, create a mapping of each element's index in the inorder array.
- Then recursively pick elements from the preorder array to form the root, left, and right subtrees using the mapping from inorder.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays represent valid preorder and inorder traversals of the same binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]`  \
  **Explanation:** The binary tree can be reconstructed as follows: root is 3 (first in preorder), the left subtree is [9], and the right subtree is [20,15,7]. The resulting tree is:

       3
      / \
     9   20
          /  \
         15   7

This tree matches the given preorder and inorder traversals.

- **Input:** `preorder = [1], inorder = [1]`  \
  **Explanation:** The tree consists of a single node with value 1, forming a trivial tree where the preorder and inorder arrays both contain just the value [1].

- **Input:** `preorder = [10,5,1,7,15,12,20], inorder = [1,5,7,10,12,15,20]`  \
  **Explanation:** The tree can be reconstructed by recognizing the root (10) from the preorder array, and the left and right subtrees by dividing the inorder array based on the root value.

{{< dots >}}
## Approach 🚀
To solve this problem, we use a recursive approach. By using the preorder array to determine the root nodes and the inorder array to determine the left and right subtrees, we can efficiently reconstruct the binary tree.

### Initial Thoughts 💭
- The first element of preorder is always the root, and inorder helps us identify the left and right subtrees.
- We can use a hashmap to quickly find the index of a node in the inorder array, allowing us to divide the array and construct the tree recursively.
{{< dots >}}
### Edge Cases 🌐
- If either the preorder or inorder array is empty, return NULL as there is no tree to construct.
- Ensure the algorithm can handle arrays with up to 3000 elements efficiently.
- Handle trees where all nodes are either to the left or right (skewed trees).
- The arrays must contain unique values, ensuring no ambiguity when building the tree.
{{< dots >}}
## Code 💻
```cpp
map<int, int> mp;
vector<int> preorder, inorder;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    this->preorder = preorder;
    this->inorder = inorder;

    for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

    return helper(0, 0, inorder.size() - 1);
}

TreeNode* helper(int ps, int is, int ie) {
    if(ps >= preorder.size() || is > ie) return NULL;

    TreeNode* root = new TreeNode(preorder[ps]);
    root->left  = helper(ps + 1, is, mp[root->val] - 1);
    root->right = helper(ps + mp[root->val] - is + 1, mp[root->val] + 1, ie);

    return root;
}
```

This code reconstructs a binary tree from its preorder and inorder traversals using a recursive approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	map<int, int> mp;
	```
	Declare a map to store the index of each element from the inorder traversal for efficient look-up.

2. **Variable Declaration**
	```cpp
	vector<int> preorder, inorder;
	```
	Declare vectors to store the preorder and inorder traversal sequences of the tree.

3. **Function Definition**
	```cpp
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	```
	Define the function 'buildTree' which takes in preorder and inorder vectors and returns the root of the constructed binary tree.

4. **Assignment**
	```cpp
	    this->preorder = preorder;
	```
	Store the input preorder vector into the class-level preorder variable.

5. **Assignment**
	```cpp
	    this->inorder = inorder;
	```
	Store the input inorder vector into the class-level inorder variable.

6. **Map Population**
	```cpp
	    for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
	```
	Populate the map 'mp' with each element from the inorder traversal as the key and its index as the value.

7. **Recursive Function Call**
	```cpp
	    return helper(0, 0, inorder.size() - 1);
	```
	Call the recursive 'helper' function to construct the tree, passing the initial indices for the preorder and inorder arrays.

8. **Helper Function Definition**
	```cpp
	TreeNode* helper(int ps, int is, int ie) {
	```
	Define the 'helper' function that recursively constructs the binary tree by using preorder and inorder indices.

9. **Base Case Check**
	```cpp
	    if(ps >= preorder.size() || is > ie) return NULL;
	```
	Base case: If the current indices are out of bounds, return NULL to terminate the recursion.

10. **Node Creation**
	```cpp
	    TreeNode* root = new TreeNode(preorder[ps]);
	```
	Create a new tree node with the value from the preorder array at the current position (ps).

11. **Recursive Call**
	```cpp
	    root->left  = helper(ps + 1, is, mp[root->val] - 1);
	```
	Recursively build the left subtree by updating the preorder and inorder indices.

12. **Recursive Call**
	```cpp
	    root->right = helper(ps + mp[root->val] - is + 1, mp[root->val] + 1, ie);
	```
	Recursively build the right subtree by updating the preorder and inorder indices.

13. **Return Node**
	```cpp
	    return root;
	```
	Return the root node of the current subtree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, we traverse each node once and use the hashmap lookup to find indices in O(1) time, resulting in O(n) time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use O(n) space to store the hashmap and the recursive stack. In the worst case (a skewed tree), the depth of the recursion is O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)

---
{{< youtube GeltTz3Z1rw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
