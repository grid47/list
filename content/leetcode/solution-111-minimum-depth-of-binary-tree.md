
+++
authors = ["grid47"]
title = "Leetcode 111: Minimum Depth of Binary Tree"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 111: Minimum Depth of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/111.webp"
youtube = "Ukbbnzxmd8o"
youtube_upload_date="2023-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/Ukbbnzxmd8o/sddefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/111.webp" 
    alt="A deep tree with soft, glowing light reaching the minimal depth, highlighting the shortest path."
    caption="Solution to LeetCode 111: Minimum Depth of Binary Tree Problem"
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
    int minDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        if(root->left && root->right) {
            return 1 + ((l < r)? l: r);            
        }
        
        if(root->left) {
            return 1 + l;                        
        }

        return 1 + r;                        
    }
};
{{< /highlight >}}
---

### 🌳 **Problem Statement: Find the Minimum Depth of a Binary Tree**

The task is to find the **minimum depth** of a binary tree. The **minimum depth** is defined as the length of the shortest path from the root node to any leaf node. A **leaf node** is a node with no children, meaning both its left and right children are `NULL`.

For example, consider the binary tree:

```
        1
       / \
      2   3
       \
        4
```

In this case, the minimum depth is `2` (root → 3), since it’s the shortest path to a leaf node. For an empty tree, the minimum depth is `0`.

---

### 🧠 **Approach to Solve the Minimum Depth Problem**

To solve this problem, we use a **depth-first search (DFS)** approach. The algorithm recursively explores the tree’s nodes from top to bottom, calculating the depth of each subtree. Here’s the breakdown:

1. **Base Case:**
   - If the current node is `NULL` (i.e., the tree is empty), return `0`, as an empty tree has no depth.

2. **Recursive Calculation of Depth:**
   - If both left and right children of the node are present, compute the depth for both subtrees and return the minimum of the two.
   - If only one child is present, return the depth of that subtree plus 1, as the path to the leaf will include that subtree.

3. **Final Result:**
   - The minimum depth will be the shortest path from the root to a leaf node, which is calculated recursively.

---

### 🔧 **Code Breakdown: Step-by-Step**

#### **Step 1: Handle the Empty Tree**

```cpp
if (root == NULL) return 0;
```

- If the root is `NULL`, the tree is empty, so we return `0` because an empty tree has no depth.

#### **Step 2: Recursive Calculation for Left and Right Subtrees**

```cpp
int l = minDepth(root->left);
int r = minDepth(root->right);
```

- We recursively calculate the minimum depth of the left (`l`) and right (`r`) subtrees. The recursion continues until the base case (a `NULL` node) is encountered.

#### **Step 3: Calculate the Minimum Depth Based on Child Nodes**

```cpp
if (root->left && root->right) {
    return 1 + ((l < r) ? l : r);
}
```

- If both left and right children are non-null, return `1 + min(l, r)`, where `l` and `r` are the depths of the left and right subtrees. This ensures we find the shortest path to a leaf.

#### **Step 4: Handle the Case When One Child Is Null**

```cpp
if (root->left) {
    return 1 + l;
}
```

- If the left child is `NULL`, the minimum depth will be `1 + depth of the right subtree`, as there is no left child to traverse.

```cpp
return 1 + r;
```

- Similarly, if the right child is `NULL`, the minimum depth will be `1 + depth of the left subtree`.

#### **Final Result:**
- The recursion continues until all nodes are visited, and the function returns the minimum depth from the root to any leaf node.

---

### ⏱️ **Time and Space Complexity**

#### **Time Complexity: O(n)**

- The algorithm visits each node exactly once to compute its depth. The time complexity is linear with respect to the number of nodes `n` in the tree, so it is **O(n)**.

#### **Space Complexity: O(h)**

- The space complexity is dominated by the recursion stack. In the worst case, the tree is completely unbalanced, resulting in a recursion depth of `h = n`, giving a space complexity of **O(n)**.
- In the best case, if the tree is balanced, the height `h` would be **O(log n)**, and the space complexity would be **O(log n)**.

---

### 🔍 **Example Walkthrough**

Let’s walk through an example to see how the solution works.

#### **Example 1: A Balanced Binary Tree**

Consider the following tree:

```
        1
       / \
      2   3
     / \
    4   5
```

- The root is `1`, and its left child is `2` and right child is `3`.
- We first call `minDepth(root)` for node `1`.
- The left subtree (rooted at `2`) and the right subtree (rooted at `3`) are explored.
- Recursively, the minimum depth of the left and right subtrees is computed:
  - The left child of node `2` is `4` (leaf), and the right child is `5` (leaf). The minimum depth of this subtree is `2`.
  - The right subtree rooted at `3` is a leaf node, so its depth is `1`.
- The minimum depth of the entire tree is `1 + min(2, 1) = 2`.

#### **Example 2: An Unbalanced Binary Tree**

Consider the following tree:

```
        1
       /
      2
     /
    3
   /
  4
```

- The root is `1`, and its left child is `2`, which has a left child `3`, and so on.
- We recursively find the minimum depth of each subtree:
  - The left subtree continues until node `4`, which is a leaf node.
- The minimum depth of the entire tree is `4`, since there is only one branch to follow (root → 2 → 3 → 4).

---

### 🚀 **Conclusion**

The solution to finding the minimum depth of a binary tree uses **depth-first search (DFS)** to explore each node’s depth recursively. The algorithm computes the depth of each subtree and returns the shortest path to a leaf node. With a time complexity of **O(n)** and a space complexity of **O(h)**, this solution is optimal for handling both balanced and unbalanced trees. The use of recursion makes the solution clean and efficient.

Happy coding! 🌱

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)

---
{{< youtube Ukbbnzxmd8o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
