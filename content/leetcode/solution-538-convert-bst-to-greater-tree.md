
+++
authors = ["grid47"]
title = "Leetcode 538: Convert BST to Greater Tree"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 538: Convert BST to Greater Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/538.webp"
youtube = "AFDxiYO9XzY"
youtube_upload_date="2023-06-09"
youtube_thumbnail="https://i.ytimg.com/vi/AFDxiYO9XzY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/538.webp" 
    alt="A binary search tree where each node is gradually updated to a greater tree, with each transformation softly highlighted."
    caption="Solution to LeetCode 538: Convert BST to Greater Tree Problem"
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

    int sum = 0;

public:

    TreeNode* convertBST(TreeNode* root) {
        convert(root);
        return root;
    }

    void convert(TreeNode* root) {
        if(!root) return;
        convert(root->right);
        root->val += sum;
        sum = root->val;
        convert(root->left);
    }

};
{{< /highlight >}}
---

### Problem Statement

The problem asks to convert a Binary Search Tree (BST) into a Greater Tree, where each node's value is replaced by the sum of all node values greater than or equal to the node's value in the original BST. The idea is to traverse the tree in a specific order and accumulate the sum as we go, updating each node with the accumulated sum.

### Approach

This problem involves transforming a given Binary Search Tree (BST) to a Greater Tree. The core idea is to traverse the tree in a reverse in-order fashion (right, root, left) to accumulate values. This reverse traversal ensures that at each node, we have already visited all the nodes that have a greater value. Here's how the approach works step by step:

1. **In-Order Traversal**: In a BST, an in-order traversal (left, root, right) will visit the nodes in increasing order of values. To accumulate the sum of all greater nodes, we need to traverse the tree in the reverse order, i.e., right, root, left.

2. **Accumulate Sum**: As we traverse the tree in reverse in-order (right to left), we maintain a running sum (`sum`). When visiting a node, we update its value by adding the current value of `sum` to the node's value. Then, we update `sum` to reflect the new value of the node.

3. **Recursive Strategy**: The solution involves a recursive depth-first search (DFS) to visit each node in the reverse in-order sequence. The DFS will start at the rightmost node (the largest node in the BST), accumulate the sum, update the node's value, and then proceed to the left subtree.

### Code Breakdown (Step by Step)

1. **TreeNode Structure**:
   - We begin with a `TreeNode` struct definition, where each node contains an integer value (`val`), and pointers to the left and right children (`left`, `right`).
   - The constructor allows us to initialize nodes either with a value or with a left and right child as well.

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

2. **Main Solution Class**:
   - The `Solution` class contains the function `convertBST` which initiates the conversion of the BST to a Greater Tree.
   - It also contains a helper function `convert` that performs the actual recursive traversal and transformation.

```cpp
class Solution {
    int sum = 0;  // Initialize sum to 0 to accumulate the values.
```

3. **convertBST Function**:
   - This function is the entry point of the solution and calls the recursive `convert` function.
   - The `convertBST` function returns the root of the modified tree after conversion.

```cpp
    TreeNode* convertBST(TreeNode* root) {
        convert(root);  // Start converting the tree.
        return root;  // Return the root of the modified tree.
    }
```

4. **convert Function**:
   - The `convert` function is a recursive function that traverses the tree in reverse in-order.
   - The base case checks if the `root` is `nullptr`. If it is, the function simply returns as there are no nodes to process.
   - The function first recurses on the right child, then updates the node’s value with the accumulated sum, and finally recurses on the left child.

```cpp
    void convert(TreeNode* root) {
        if(!root) return;  // If the node is null, return (base case).
        
        convert(root->right);  // First, visit the right subtree (larger nodes).
        
        root->val += sum;  // Update the current node's value with the accumulated sum.
        sum = root->val;  // Update the sum to the current node's new value.
        
        convert(root->left);  // Finally, visit the left subtree (smaller nodes).
    }
};
```

### Complexity

#### Time Complexity:
- **Traversal Time**: The algorithm performs a depth-first traversal of the tree. Since each node is visited exactly once, the time complexity is proportional to the number of nodes in the tree, i.e., `O(n)`, where `n` is the number of nodes in the binary search tree.
- **Overall Time Complexity**: `O(n)` where `n` is the number of nodes in the tree.

#### Space Complexity:
- **Recursive Stack**: The space complexity is determined by the depth of the recursive call stack. In the worst case, the tree could be skewed (i.e., a linked list), resulting in a recursion depth of `O(n)`. In a balanced tree, the recursion depth would be `O(log n)`. Thus, the space complexity is `O(n)` in the worst case, but it can be `O(log n)` for balanced trees.
- **Overall Space Complexity**: `O(n)` in the worst case due to recursion stack.

### Conclusion

This solution effectively converts a Binary Search Tree (BST) into a Greater Tree where each node's value is replaced by the sum of all node values greater than or equal to the node's original value. The approach relies on a reverse in-order traversal to accumulate values from the rightmost node to the leftmost node. This ensures that at each step, the node is updated with the sum of all greater nodes in the tree. The solution is efficient with a time complexity of `O(n)` and space complexity of `O(n)` (in the worst case), making it optimal for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-bst-to-greater-tree/description/)

---
{{< youtube AFDxiYO9XzY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
