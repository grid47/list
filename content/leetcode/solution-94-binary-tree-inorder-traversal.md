
+++
authors = ["grid47"]
title = "Leetcode 94: Binary Tree Inorder Traversal"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 94: Binary Tree Inorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/94.webp"
youtube = "g_S5WuasWUE"
youtube_upload_date="2022-03-12"
youtube_thumbnail="https://i.ytimg.com/vi/g_S5WuasWUE/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/94.webp" 
    alt="A glowing tree with nodes softly illuminating as the inorder traversal progresses."
    caption="Solution to LeetCode 94: Binary Tree Inorder Traversal Problem"
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};
{{< /highlight >}}
---

### 🌳 **Inorder Traversal of a Binary Tree**

In this problem, we are tasked with performing an **inorder traversal** of a binary tree. The inorder traversal visits nodes in the following order:
1. Left subtree
2. Root node
3. Right subtree

#### Example

For the binary tree:

```
       1
      / \
     2   3
    / \
   4   5
```

The inorder traversal of this tree would be: `[4, 2, 5, 1, 3]`.

### Approach

To solve this problem, we use an **iterative approach** with a stack to simulate the recursive process of inorder traversal. While recursion uses the system's call stack, the iterative approach uses an explicit stack data structure to manage the traversal.

In an inorder traversal:
- We visit the left subtree first, then the node itself, and then the right subtree.
- The key challenge is to backtrack after visiting the left subtree so that we can visit the root and then explore the right subtree. A stack helps manage this process.

### Steps

1. **Initialize** the stack and a result vector.
2. **Traverse the left subtree**: Move to the leftmost node, pushing nodes onto the stack as we go.
3. **Visit the root**: When we reach a node with no left child, pop it from the stack and add its value to the result vector.
4. **Move to the right subtree**: After visiting a node, move to its right child and repeat the process.
5. **Repeat** until all nodes are visited.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Stack and Result Vector

```cpp
vector<int> nodes;
stack<TreeNode*> todo;
```

- `nodes`: A vector to store the result of the inorder traversal.
- `todo`: A stack to hold nodes that we need to visit.

#### Step 2: Traverse the Left Subtree

```cpp
while (root || !todo.empty()) {
    while (root) {
        todo.push(root);
        root = root->left;
    }
```

- The outer `while` loop runs as long as there are nodes to visit (`root != NULL`) or the stack is not empty (`!todo.empty()`).
- The inner `while` loop traverses the leftmost path of the tree, pushing nodes onto the stack as we go down.

#### Step 3: Process the Current Node

```cpp
root = todo.top();
todo.pop();
nodes.push_back(root->val);
```

- After reaching the leftmost node (or a `NULL` child), we:
  - Pop the top node from the stack.
  - Add its value to the `nodes` vector.

#### Step 4: Move to the Right Subtree

```cpp
root = root->right;
```

- After processing a node, we move to its right child, if it exists. If there’s no right child, `root` becomes `NULL`, and the algorithm backtracks using the stack.

#### Step 5: Return the Result

```cpp
return nodes;
```

- Once the traversal is complete, the `nodes` vector contains the node values in the correct inorder sequence. We return this vector as the final result.

### Time and Space Complexity

#### Time Complexity:
- **O(n)**, where `n` is the number of nodes in the binary tree. Each node is visited exactly once during the traversal, and each operation (push and pop from the stack) takes constant time. Thus, the overall time complexity is **O(n)**.

#### Space Complexity:
- **O(h)**, where `h` is the height of the tree. In the worst case, if the tree is skewed (like a linked list), the height could be `n`, and the space complexity would be **O(n)** due to the stack. In a balanced tree, the height is **O(log n)**, leading to **O(log n)** space complexity.

### Conclusion

The iterative approach to performing an inorder traversal using a stack is efficient and avoids deep recursion, which could be problematic for very large trees. This approach ensures an **O(n)** time complexity and **O(h)** space complexity, where `h` is the height of the tree. It is particularly useful for trees with large depths, as it avoids the risk of a stack overflow. By explicitly managing the nodes to visit with a stack, this method ensures the correct inorder sequence while keeping track of the traversal state.

---

This method is a robust, space-efficient alternative to the recursive solution and can handle trees of varying shapes and sizes without the risk of stack overflow. Happy coding! 🌟

[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

---
{{< youtube g_S5WuasWUE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
