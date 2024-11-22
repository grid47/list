
+++
authors = ["grid47"]
title = "Leetcode 230: Kth Smallest Element in a BST"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 230: Kth Smallest Element in a BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/230.webp"
youtube = "PwjF3RO9djY"
youtube_upload_date="2024-06-23"
youtube_thumbnail="https://i.ytimg.com/vi/PwjF3RO9djY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/230.webp" 
    alt="A binary search tree with nodes softly glowing, showing the kth smallest element highlighted."
    caption="Solution to LeetCode 230: Kth Smallest Element in a BST Problem"
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        // stk.push(root);
        TreeNode* node= root;
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                k--;
                if(k == 0) return node->val;
                node = node->right;
            }
        }
        return NULL;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, we are tasked with finding the `k`th smallest element in a **binary search tree (BST)**. Given the root of the tree and an integer `k`, we need to return the `k`th smallest element in the BST. The BST property ensures that for any node, the left subtree contains values smaller than the node, and the right subtree contains values larger. This structure allows us to search and traverse the tree efficiently.

---

### 🧠 Approach

To find the kth smallest element efficiently, we can take advantage of an **in-order traversal** of the BST. In-order traversal visits the nodes of a BST in ascending order, making it perfect for this problem. By counting the number of nodes visited during the traversal, we can stop as soon as we reach the `k`th smallest element.

To avoid the overhead of recursion, we'll implement this traversal iteratively using a **stack**. Here’s how we can break down the approach:

1. **In-order Traversal Using Stack**:
   - Start by pushing the leftmost nodes of the tree onto the stack.
   - Pop nodes from the stack, count them, and then move to the right children.
   - The moment we pop the `k`th node, we return its value because it's the `k`th smallest element in the tree.

2. **Edge Case Handling**:
   - No need to handle cases where `k` is invalid or out of bounds, as per problem constraints. We can assume that `k` is always valid and the tree is never empty.

---

### 🔨 Step-by-Step Code Breakdown

Let’s break down the code step-by-step for a better understanding:

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
```

- We start by declaring a stack (`stk`) to assist with the iterative traversal. The variable `node` is initially set to the root of the tree.

```cpp
        while(!stk.empty() || node) {
```

- The loop runs as long as there are nodes in the stack or nodes left to visit. This ensures we keep traversing until we reach the kth smallest node.

```cpp
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                k--;
                if(k == 0) return node->val;
                node = node->right;
            }
```

- **Traverse left**: If the current node exists, we push it onto the stack and move to its left child.
- **Process current node**: When there are no more left children (`node == NULL`), we pop a node from the stack, decrement `k`, and check if `k` has reached 0. If `k` is 0, we return the current node’s value as the `k`th smallest element.
- **Move right**: If the node has a right child, we move to the right and continue the process.

```cpp
        return NULL;
    }
};
```

- The function returns once the `k`th smallest element is found. The `return NULL` is a fallback but will never be reached as the problem guarantees the `k`th smallest element will always exist.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **In-order Traversal**: We may need to visit every node in the tree to find the kth smallest element. Each node is pushed and popped from the stack once. The time complexity is proportional to the number of nodes in the tree.
  
  - **Time Complexity**: `O(N)` where `N` is the number of nodes in the tree. However, since we stop as soon as we find the `k`th element, the time complexity is actually `O(k)` in the best case.

#### Space Complexity:
- **Stack Space**: The space used by the stack depends on the height of the tree. In the worst case, if the tree is unbalanced (like a linked list), the stack could hold all the nodes in the tree.
  
  - **Space Complexity**: `O(H)`, where `H` is the height of the tree. In the worst case (unbalanced tree), `H` could be equal to `N`. In the best case (balanced tree), `H` would be `O(log N)`.

---

### 🏁 Conclusion

This approach efficiently finds the `k`th smallest element in a BST using an **iterative in-order traversal with a stack**. By leveraging the BST’s properties, we can visit nodes in ascending order and stop as soon as we reach the desired element. This solution is optimal with a time complexity of `O(N)` and space complexity of `O(H)`, where `H` is the height of the tree.

#### Key Takeaways:
- **In-order Traversal** ensures nodes are visited in sorted order.
- **Iterative Solution** avoids recursion, making it suitable for large trees.
- **Time Complexity**: `O(N)` in the worst case, but can be `O(k)` if `k` is small.
- **Space Complexity**: `O(H)`, where `H` is the tree height.

This method is both time and space efficient and provides a reliable way to solve the problem for any given BST!

[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

---
{{< youtube PwjF3RO9djY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
