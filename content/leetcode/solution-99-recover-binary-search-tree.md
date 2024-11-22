
+++
authors = ["grid47"]
title = "Leetcode 99: Recover Binary Search Tree"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 99: Recover Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/99.webp"
youtube = "bJBwOMPhe6Y"
youtube_upload_date="2020-10-31"
youtube_thumbnail="https://i.ytimg.com/vi/bJBwOMPhe6Y/sddefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/99.webp" 
    alt="A tree softly rearranging its nodes, finding its balance and order."
    caption="Solution to LeetCode 99: Recover Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    TreeNode *prv = NULL, * fst = NULL , *scd = NULL;
    void inorder(TreeNode* node)
    {
        if(!node) return;
        inorder(node->left);
        if (prv && node->val < prv->val) {
            if (!fst)  fst = prv;
            scd = node; 
        }
        prv = node;
        inorder(node->right);
    }
public:
    void recoverTree(TreeNode* node) {
        inorder(node);
        swap(fst->val, scd->val);
    }
};
{{< /highlight >}}
---

### 🌳 **Recover Binary Search Tree (BST)**

The problem asks us to recover a **binary search tree (BST)** where two of its nodes have been swapped by mistake. Given a binary tree with exactly two swapped nodes, the goal is to identify these nodes and swap them back to restore the tree’s validity as a BST.

---

### 🔑 **Approach:**

To solve this problem, we need to identify the two nodes that were swapped in the tree and swap them back. The core property of a BST is that during an **in-order traversal**, the node values should be in **strictly increasing order**.

#### **Steps:**
1. **Perform an in-order traversal** of the tree.
2. During the traversal, if we find a node whose value is smaller than the previous node’s value, it indicates a violation of the BST property.
3. The nodes involved in the violation will be:
   - The **first node** that violates the property (`fst`).
   - The **second node** that violates the property (`scd`).
4. After identifying the swapped nodes, swap their values to restore the tree.

---

### 💻 **Code Breakdown (Step by Step):**

#### **1. Class Definition and Variable Declaration**

```cpp
class Solution {
    TreeNode *prv = NULL, *fst = NULL, *scd = NULL;
```

- **`prv`**: A pointer used to track the previous node during the in-order traversal.
- **`fst`**: A pointer that will store the first node involved in the swap violation.
- **`scd`**: A pointer that will store the second node involved in the swap violation.

#### **2. In-Order Traversal Function**

```cpp
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
```

- The function `inorder` performs an in-order traversal of the tree starting from the `node` passed as an argument.
- If the `node` is `NULL`, the function returns without doing anything.

```cpp
        if (prv && node->val < prv->val) {
            if (!fst)  fst = prv;
            scd = node;
        }
        prv = node;
        inorder(node->right);
    }
```

- The **in-order traversal** of the left subtree is done first, and then the value of the current node (`node->val`) is compared to the previous node’s value (`prv->val`).
- If the current node’s value is less than the previous node’s value (`node->val < prv->val`), this indicates a violation of the BST property.
  - The **first violation** occurs when we encounter the first node that is out of order, which is stored in `fst`.
  - The **second violation** node is stored in `scd`.
- The `prv` pointer is updated to point to the current node (`node`) to continue the traversal.
- The traversal then proceeds to the right child of the current node (`node->right`).

#### **3. Recover the Tree**

```cpp
public:
    void recoverTree(TreeNode* node) {
        inorder(node);
        swap(fst->val, scd->val);
    }
```

- The `recoverTree` function is the entry point. It takes the root of the tree as an argument (`node`).
- The function calls the `inorder` function to identify the swapped nodes.
- After identifying the swapped nodes, the values are swapped back using the `swap(fst->val, scd->val)` statement.

---

### 🧠 **Time and Space Complexity:**

#### **Time Complexity:**

The time complexity of this solution is **O(n)**, where `n` is the number of nodes in the binary tree. This is because we perform a single in-order traversal, visiting each node exactly once.

#### **Space Complexity:**

The space complexity is **O(h)**, where `h` is the height of the tree. This space is used by the recursion stack during the in-order traversal. In the worst case (unbalanced tree), the height `h` could be equal to `n`, so the space complexity would be **O(n)**. However, for a balanced tree, the space complexity would be **O(log n)**.

---

### 🎯 **Conclusion:**

This solution efficiently solves the problem of recovering a BST with two swapped nodes by performing an **in-order traversal** of the tree. The **in-order traversal** ensures that we can identify the two swapped nodes in a single pass through the tree, making this approach time-efficient with a complexity of **O(n)**.

The solution uses constant space, aside from the recursion stack, ensuring space efficiency with a worst-case space complexity of **O(h)**. This approach efficiently restores the validity of the binary search tree, ensuring the tree structure is properly recovered.

---

**Happy coding!** 🌱✨

[`Link to LeetCode Lab`](https://leetcode.com/problems/recover-binary-search-tree/description/)

---
{{< youtube bJBwOMPhe6Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
