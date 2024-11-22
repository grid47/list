
+++
authors = ["grid47"]
title = "Leetcode 114: Flatten Binary Tree to Linked List"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 114: Flatten Binary Tree to Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Stack","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/114.webp"
youtube = "rKnD7rLT0lI"
youtube_upload_date="2021-09-16"
youtube_thumbnail="https://i.ytimg.com/vi/rKnD7rLT0lI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/114.webp" 
    alt="A soft tree smoothly transforming into a linear, glowing list of nodes, symbolizing a flattened structure."
    caption="Solution to LeetCode 114: Flatten Binary Tree to Linked List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void flatten(TreeNode* root) {

        if( root == NULL) return;

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode* node = root;
        while(node->right) node = node->right;

        node->right = tmp;
        flatten(root->right); 

    }
};
{{< /highlight >}}
---

### 🌳 **Problem Statement: Flatten a Binary Tree into a Linked List**

The task is to **flatten a binary tree** into a linked list, **in-place**. This means that the binary tree should be modified such that:
- The left child of every node is set to `nullptr`.
- The right child points to the next node in the pre-order traversal sequence.

Consider the following binary tree:

```
          1
         / \
        2   5
       / \   \
      3   4   6
```

After flattening, the tree should look like this:

```
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
```

In essence, we are transforming the tree into a linked list where each node points to the next node in a pre-order sequence, and all left children are removed.

---

### 🚀 **Approach: Pre-Order Traversal to Flatten the Tree**

The goal is to flatten the tree using **pre-order traversal** while modifying the tree in place. Here's how we approach the problem:

1. **Start from the root:** Begin by checking if the root is `NULL`. If it is, the tree is already empty, and we don't need to do anything.

2. **Flatten the left subtree:** Recursively flatten the left child. Before doing that, we store the right child temporarily, since we'll need it after flattening the left subtree.

3. **Rearrange the nodes:** After flattening the left subtree:
   - Set the current node's left child to `nullptr` (since it's now part of a linked list).
   - Move the flattened left subtree to the right child of the current node.

4. **Go to the end of the right subtree:** Traverse the new right subtree (which now contains the flattened left subtree) to find the last node. We’ll attach the original right subtree to the end of this new right subtree.

5. **Flatten the right subtree:** Recursively flatten the right child of the current node.

---

### 🧑‍💻 **Code Breakdown (Step-by-Step)**

#### 1. Function Definition:

```cpp
void flatten(TreeNode* root) {
    if( root == NULL) return;
```

- This is the base case of our recursion. If the root is `NULL`, we don't need to do anything, so the function simply returns.

#### 2. Temporarily Save the Right Child:

```cpp
    TreeNode* tmp = root->right;
```

- Before we modify the tree structure, we temporarily store the right child in a variable `tmp`. This ensures that we don’t lose access to the original right child while rearranging the nodes.

#### 3. Move the Left Subtree to the Right:

```cpp
    root->right = root->left;
    root->left = nullptr;
```

- Here, we move the left subtree to the right of the current node. This is the key step in flattening the tree — the left child is no longer needed, so we set it to `nullptr`.

#### 4. Traverse to the End of the New Right Subtree:

```cpp
    TreeNode* node = root;
    while(node->right) node = node->right;
```

- After moving the left subtree to the right, we need to find the last node in this newly modified right subtree. We do this by traversing through the right children until we reach the last node.

#### 5. Attach the Original Right Subtree:

```cpp
    node->right = tmp;
```

- Once we find the last node in the new right subtree, we attach the original right subtree (stored in `tmp`) to the end of the new right subtree.

#### 6. Recursively Flatten the Right Subtree:

```cpp
    flatten(root->right);
}
```

- Finally, we recursively flatten the right subtree. This ensures that the entire tree gets flattened, starting from the modified right child.

---

### ⏱️ **Time and Space Complexity**

#### **Time Complexity: O(n)**

- The time complexity is **O(n)**, where `n` is the number of nodes in the binary tree. This is because each node is visited once during the traversal, and each operation inside the function (like setting pointers) takes constant time.

#### **Space Complexity: O(h)**

- The space complexity is **O(h)**, where `h` is the height of the tree, because of the recursion stack.
  - In the worst case (a completely unbalanced tree), the height is `n`, and the space complexity is **O(n)**.
  - In the best case (a balanced tree), the height is `log n`, leading to a space complexity of **O(log n)**.

---

### 🌟 **Example Walkthrough**

#### Example 1: Balanced Binary Tree

Consider this tree:

```
        1
       / \
      2   3
     / \
    4   5
```

- Start from the root node `1`, flatten the left subtree (`2 → 4 → 5`), and move it to the right.
- Then, recursively flatten the right subtree of node `1` (which is just `3`).

The result is the flattened tree:

```
1
 \
  2
   \
    4
     \
      5
       \
        3
```

#### Example 2: Unbalanced Tree

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

- Flatten the left subtree (`2 → 3 → 4`), and move it to the right of `1`.
- Then, flatten the right subtree (which is `NULL`).

The result is the flattened tree:

```
1
 \
  2
   \
    3
     \
      4
```

---

### 🏁 **Conclusion**

This solution efficiently flattens a binary tree into a linked list in place using **pre-order traversal**. The time complexity is **O(n)**, and the space complexity is **O(h)**, where `n` is the number of nodes and `h` is the height of the tree. The algorithm avoids extra space by modifying the tree directly, making it space-efficient.

The recursive approach is both intuitive and elegant, flattening the tree step-by-step by moving the left subtree to the right and recursively processing the right children. This solution handles edge cases such as empty trees and trees with only one node seamlessly.

In summary, this approach provides an optimal and clean solution to flattening a binary tree into a linked list, with both time and space complexities suitable for large trees.

[`Link to LeetCode Lab`](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)

---
{{< youtube rKnD7rLT0lI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
