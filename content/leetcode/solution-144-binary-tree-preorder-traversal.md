
+++
authors = ["grid47"]
title = "Leetcode 144: Binary Tree Preorder Traversal"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 144: Binary Tree Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/144.webp"
youtube = "WIfjmUTXnlE"
youtube_upload_date="2022-06-29"
youtube_thumbnail="https://i.ytimg.com/vi/WIfjmUTXnlE/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/144.webp" 
    alt="A tree with nodes glowing sequentially from root to leaf, following a smooth, glowing path."
    caption="Solution to LeetCode 144: Binary Tree Preorder Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pre(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
};
{{< /highlight >}}
---

### 📝 **Problem Understanding: Preorder Traversal of a Binary Tree**

We are asked to perform a **preorder traversal** on a binary tree. In preorder traversal, we visit the node first, then recursively visit its left subtree, and finally, its right subtree.

#### Example:
- **Input**: `root = [1, null, 2, 3]`
  - **Output**: `[1, 2, 3]`

In this traversal:
1. Visit the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.

---

### 🔧 **Approach: Recursive Preorder Traversal**

To implement this, we can use a **recursive approach**:
1. **Base Case**: If the node is `NULL`, we return (i.e., nothing more to process).
2. **Recursive Case**: If the node is not `NULL`, we:
   - Process the node (add its value to the result).
   - Recursively call the function for the left child.
   - Recursively call the function for the right child.

This approach follows the standard definition of preorder traversal.

---

### 🖥️ **Code Breakdown: Step-by-Step**

#### Step 1: Define the TreeNode Structure
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
```
- `TreeNode` represents a node in the binary tree, with:
  - `val`: The value stored in the node.
  - `left`: Pointer to the left child.
  - `right`: Pointer to the right child.
  
#### Step 2: Define the Recursive Preorder Traversal Function
```cpp
void pre(TreeNode* root, vector<int>& ans) {
    if (!root) return;  // Base case: if the node is null, do nothing.
    ans.push_back(root->val);  // Visit the root node (process it).
    pre(root->left, ans);  // Recursively traverse the left subtree.
    pre(root->right, ans);  // Recursively traverse the right subtree.
}
```
- **Base Case**: If the node is `NULL`, return without doing anything.
- **Recursive Case**: Process the node (add `root->val` to `ans`), then recursively traverse the left and right children.

#### Step 3: Define the Preorder Traversal Wrapper Function
```cpp
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;  // Initialize an empty vector to store the result.
    pre(root, ans);  // Call the recursive preorder function.
    return ans;  // Return the result vector.
}
```
- This function initializes an empty vector `ans` to hold the preorder traversal result.
- It then calls the recursive function `pre` to process the tree, starting from the root.
- Finally, it returns the result stored in `ans`.

---

### 🧮 **Time and Space Complexity**

#### ⏱️ **Time Complexity**:
- **O(n)**: In the worst case, we visit each node exactly once, where `n` is the number of nodes in the binary tree. Thus, the time complexity is linear, **O(n)**.

#### 🧳 **Space Complexity**:
- **O(n)**: The space complexity is determined by:
  - The space required to store the result vector `ans`, which holds `n` values.
  - The recursive call stack. In the worst case (for a completely unbalanced tree), the recursion depth can be `O(n)`.

Thus, the overall space complexity is **O(n)**.

---

### 🎯 **Conclusion: Efficient Recursive Solution**

This recursive solution provides a straightforward and efficient way to perform a preorder traversal on a binary tree. It works by visiting the node first, then recursively traversing its left and right subtrees, ensuring the correct order of traversal.

#### Key Insights:
- **Simple Recursive Solution**: The algorithm uses recursion to process each node, making the solution easy to understand and implement.
- **Optimal Time Complexity**: The time complexity is linear **O(n)**, which is optimal for traversing every node in the tree.
- **Space Complexity Considerations**: The space complexity is **O(n)** due to the result vector and the recursive call stack.

This approach is highly effective for handling medium to large binary trees and ensures minimal memory usage with a clear and concise implementation.

[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)

---
{{< youtube WIfjmUTXnlE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
