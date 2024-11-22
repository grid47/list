
+++
authors = ["grid47"]
title = "Leetcode 235: Lowest Common Ancestor of a Binary Search Tree"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 235: Lowest Common Ancestor of a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/235.webp"
youtube = "ML6vGnziUaI"
youtube_upload_date="2023-02-11"
youtube_thumbnail="https://i.ytimg.com/vi/ML6vGnziUaI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/235.webp" 
    alt="Two paths glowing brightly as they meet at the lowest common ancestor in a binary search tree."
    caption="Solution to LeetCode 235: Lowest Common Ancestor of a Binary Search Tree Problem"
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
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
{{< /highlight >}}
---

### 🌟 Problem Statement

In this problem, we are tasked with finding the **Lowest Common Ancestor (LCA)** of two nodes in a **Binary Search Tree (BST)**. The **LCA** of two nodes `p` and `q` is the deepest node in the tree that is an ancestor of both `p` and `q`. Simply put, it's the most recent common node on the path from `p` to the root and from `q` to the root.

In a **Binary Search Tree**, the key property to remember is:
- The **left subtree** contains nodes with values less than the root node.
- The **right subtree** contains nodes with values greater than the root node.

With this in mind, we can traverse the BST in a smart way to locate the **LCA** of `p` and `q`.

---

### 🧠 Approach

To solve this problem efficiently, we can leverage the properties of the **Binary Search Tree (BST)**. The observation here is:
- If both `p` and `q` are smaller than the current node’s value, then both nodes must lie in the **left subtree**.
- If both `p` and `q` are greater than the current node’s value, then both nodes must lie in the **right subtree**.
- If one node is smaller and the other is greater (or one of them is equal to the current node), we have found the **Lowest Common Ancestor**.

Here’s the plan:
1. Start at the **root** of the tree.
2. If both `p` and `q` are on the right side of the current node, move to the **right child**.
3. If both `p` and `q` are on the left side of the current node, move to the **left child**.
4. If one of `p` or `q` is on one side and the other is on the opposite side (or one of them is equal to the current node), the current node is the **LCA**.

This approach is efficient and works in **O(log n)** time for **balanced trees**.

---

### 🔨 Step-by-Step Code Breakdown

Let's walk through the code implementation step-by-step.

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
```
- We define a `Solution` class and create the `lowestCommonAncestor` function. This function takes the `root` node of the tree, and two nodes `p` and `q` as input, and returns their **LCA**.

```cpp
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
```
- First, we check if both `p` and `q` are larger than the current `root` node. If they are, it means both nodes are in the **right subtree**. Therefore, we move to the **right child** (`root->right`).

```cpp
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
```
- If both `p` and `q` are smaller than the current `root` node, then both nodes lie in the **left subtree**. Thus, we recursively call the function on the **left child** (`root->left`).

```cpp
        return root;
```
- If neither of the above conditions is true, then one of the following must be true:
  - One of `p` or `q` is smaller and the other is larger.
  - Or one of them is equal to the current `root` node.
  
  In either case, the current node is the **LCA** of `p` and `q`, and we return it.

---

### 📈 Complexity Analysis

#### ⏱️ Time Complexity:
- The time complexity is **O(h)**, where `h` is the height of the tree.
  - For a **balanced BST**, the height is **O(log n)**, where `n` is the number of nodes in the tree.
  - For an **unbalanced BST**, the height could be as large as **O(n)** in the worst case (like a linked list).

Thus, the time complexity is:
- **O(log n)** for balanced trees.
- **O(n)** for unbalanced trees.

#### 💾 Space Complexity:
- The space complexity is **O(1)** since we are only using a constant amount of extra space for the recursion.
- However, considering the recursive call stack, the space complexity is **O(h)**, where `h` is the height of the tree (the deepest recursion level).

---

### 🏁 Conclusion

This solution provides an efficient way to find the **Lowest Common Ancestor (LCA)** in a **Binary Search Tree (BST)** by utilizing its inherent properties:
- Nodes smaller than the current node lie in the **left subtree**.
- Nodes greater than the current node lie in the **right subtree**.
- The **LCA** is found when `p` and `q` are on either side of the current node or one of them is equal to the node itself.

With a **time complexity of O(log n)** for balanced trees and **space complexity of O(1)**, this solution is both **time and space efficient**, making it ideal for **coding interviews** and **algorithm challenges**.

#### Key Highlights:
- **Efficient for BSTs**: This solution is optimal for binary search trees due to the logarithmic time complexity.
- **Simple and Elegant**: The approach is straightforward and involves a simple recursive strategy with conditions to navigate the tree.
- **Space Efficient**: Only a constant amount of space is used, making the solution space efficient.

This method is an ideal way to find the **LCA** in a **BST**, and its simplicity makes it a go-to solution for many algorithmic problems.

--- 

💡 **Remember**: The power of BST lies in its structure, and by utilizing this structure wisely, we can efficiently solve many problems like finding the **LCA**! Keep practicing! 😎

[`Link to LeetCode Lab`](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

---
{{< youtube ML6vGnziUaI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
