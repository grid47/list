
+++
authors = ["grid47"]
title = "Leetcode 236: Lowest Common Ancestor of a Binary Tree"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 236: Lowest Common Ancestor of a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/236.webp"
youtube = "gRHnWbKiUIE"
youtube_upload_date="2021-01-23"
youtube_thumbnail="https://i.ytimg.com/vi/gRHnWbKiUIE/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/236.webp" 
    alt="Similar to the previous idea, with paths gently intersecting to show the common ancestor in a non-search tree."
    caption="Solution to LeetCode 236: Lowest Common Ancestor of a Binary Tree Problem"
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        return !left? right: !right? left : root;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, we need to find the **Lowest Common Ancestor (LCA)** of two nodes in a **Binary Tree**. The LCA is the deepest node in the tree that is an ancestor of both nodes `p` and `q`. 

A binary tree is made up of nodes where each node has:
- A value (`val`)
- A left child (`left`)
- A right child (`right`)

Your task is to identify and return the **Lowest Common Ancestor** of nodes `p` and `q`.

---

### 🧠 Approach

This problem is a great opportunity to apply **recursion** in a **post-order traversal** style! Here's how we can approach the solution:

1. **Base Case**: 
   - If the current node is `NULL`, or if it matches either `p` or `q`, we return the current node.
   - This base case is crucial because it tells us when to stop the recursion and start returning nodes.

2. **Recursive Case**:
   - Search the left and right subtrees of the current node for `p` and `q`.
   - If one of `p` or `q` is found in both subtrees, the current node is their **Lowest Common Ancestor**.
   - If one subtree returns a non-`NULL` node, that node must be the **LCA**.

3. **Decision Making**:
   - If the left and right recursive calls both return a non-`NULL` node, it means one node was found in the left and the other in the right, so the current node is the **LCA**.
   - If only one of the recursive calls returns a non-`NULL` node, that node must be the **LCA**.

It's like a treasure hunt in the tree, where we're trying to find the deepest common node between the paths from the root to `p` and `q`. 🌳✨

---

### 🔨 Step-by-Step Code Breakdown

Let's break the code into smaller chunks to understand it clearly:

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
```
- We define the `lowestCommonAncestor` function within a `Solution` class. The function accepts three parameters: the `root` of the tree, and the two nodes `p` and `q`.

```cpp
        if(!root || root == p || root == q) return root;
```
- **Base case**: If the `root` is `NULL` (no node to check) or if the `root` matches either `p` or `q`, we return the `root`. This means we've either reached a leaf node or found one of the nodes we are searching for.

```cpp
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
```
- We recursively search for `p` and `q` in the left and right subtrees. 
- The result from the left subtree is stored in `left`, and the result from the right subtree is stored in `right`.

```cpp
        return !left ? right : !right ? left : root;
```
- **Decision making**: Here's how we decide where the **LCA** is:
  - If `left` is `NULL`, it means `p` and `q` aren't found in the left subtree, so we return `right`.
  - If `right` is `NULL`, it means `p` and `q` aren't found in the right subtree, so we return `left`.
  - If both `left` and `right` are non-`NULL`, it means `p` and `q` were found in both subtrees. Therefore, the current `root` must be the **Lowest Common Ancestor**.

---

### 📊 Complexity Analysis

Now let's analyze the efficiency of our solution:

#### ⏱️ Time Complexity:
- **O(n)**, where `n` is the number of nodes in the tree.
  - In the worst case, we may need to visit every single node to find the **LCA**, especially in unbalanced trees.
  - In a balanced tree, the time complexity would still be **O(n)**, because we still explore all nodes, but the depth is more manageable.

#### 💾 Space Complexity:
- **O(h)**, where `h` is the height of the tree.
  - This is the space needed for the recursive call stack.
  - In the worst case (unbalanced tree), the height `h` is **O(n)**, so the space complexity would be **O(n)**.
  - In the best case (balanced tree), the height `h` is **O(log n)**, so the space complexity would be **O(log n)**.

---

### 🏁 Conclusion

By leveraging recursion, we can efficiently find the **Lowest Common Ancestor (LCA)** of two nodes in a **Binary Tree**. Here's what we've learned:

- **Base Case**: If we reach `NULL` or find `p` or `q`, we return the current node.
- **Recursive Search**: We search both the left and right subtrees.
- **Decision Making**: The node where the paths to `p` and `q` split is the **LCA**.

This approach is not only intuitive but also powerful, as it works well for both balanced and unbalanced trees. Plus, the time complexity of **O(n)** and space complexity of **O(h)** ensures that it handles even large trees efficiently.

#### Key Takeaways:
- The recursive approach is simple and effective.
- The space complexity is manageable, and the time complexity is linear with respect to the number of nodes in the tree.
- This solution is commonly used in interviews and competitive programming due to its clarity and efficiency.

---

Ready to tackle the problem yourself? 🧑‍💻 Try implementing it, and don't forget to test it with different tree shapes! 🌟

[`Link to LeetCode Lab`](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)

---
{{< youtube gRHnWbKiUIE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
