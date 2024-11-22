
+++
authors = ["grid47"]
title = "Leetcode 872: Leaf-Similar Trees"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 872: Leaf-Similar Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Nr8dbnL0_cM"
youtube_upload_date="2024-01-09"
youtube_thumbnail="https://i.ytimg.com/vi/Nr8dbnL0_cM/maxresdefault.jpg"
+++



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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1), s2.push(root2);
        while(!s1.empty() && !s2.empty())
            if(dfs(s1) != dfs(s2)) return false;
        return s1.empty() && s2.empty();
    }
    
    int dfs(stack<TreeNode*> &stk) {
        while(true) {
            TreeNode* node = stk.top(); stk.pop();
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
            if(!node->left && !node->right) return node->val;
        }
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are asked to determine whether two binary trees are "leaf similar." Two trees are considered leaf similar if their leaf nodes (the nodes that do not have left or right children) form the same sequence when traversed from left to right. Specifically, we are given two binary trees, `root1` and `root2`, and we need to check if their leaf nodes' values appear in the same order.

A leaf node is defined as a node that does not have a left or right child.

### Approach

To solve this problem, we can take advantage of **depth-first search (DFS)** to traverse the trees. We aim to compare the sequences of leaf nodes from both trees and check if they match. Here’s how the solution is structured:

1. **Use DFS for Leaf Extraction**: Perform a DFS traversal of both trees and extract the leaf nodes. This traversal will allow us to check the nodes one by one, comparing them as we go.

2. **Simultaneous DFS on Both Trees**: We use two stacks (one for each tree) to traverse both trees simultaneously. At each step, we compare the leaf nodes from both trees.

3. **Return Result Based on Comparison**: If the leaf nodes from both trees match in the same order, we return `true`; otherwise, we return `false`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1), s2.push(root2);
        
        while(!s1.empty() && !s2.empty())  // Step 1: Compare leaf nodes
            if(dfs(s1) != dfs(s2)) return false;
        
        return s1.empty() && s2.empty();  // Step 2: Ensure both stacks are empty
    }
    
    int dfs(stack<TreeNode*> &stk) {
        while(true) {  // Step 3: DFS to extract leaf node value
            TreeNode* node = stk.top(); stk.pop();
            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
            if(!node->left && !node->right) return node->val;  // Step 4: Return leaf node value
        }
    }
};
```

#### Step 1: Compare Leaf Nodes Simultaneously

```cpp
stack<TreeNode*> s1, s2;
s1.push(root1), s2.push(root2);

while(!s1.empty() && !s2.empty()) {
    if(dfs(s1) != dfs(s2)) return false;
}
```

- We use two stacks `s1` and `s2` to hold the nodes of `root1` and `root2` respectively.
- The `while` loop runs as long as both stacks are not empty. At each iteration, we pop leaf nodes from both stacks using the `dfs` function.
- If the leaf values from the two trees do not match, we return `false` immediately, indicating that the leaf nodes in both trees are not similar.

#### Step 2: Ensure Both Stacks are Empty

```cpp
return s1.empty() && s2.empty();
```

- After the loop, if both stacks are empty, we know that both trees have been completely traversed, and all leaf nodes from both trees have been compared. If no mismatches were found, we return `true`.
- If any stack is not empty, it means that one tree has more leaf nodes than the other, and we return `false`.

#### Step 3: Depth-First Search to Extract Leaf Nodes

```cpp
int dfs(stack<TreeNode*> &stk) {
    while(true) {
        TreeNode* node = stk.top(); stk.pop();
        if(node->left) stk.push(node->left);
        if(node->right) stk.push(node->right);
        if(!node->left && !node->right) return node->val;
    }
}
```

- The `dfs` function is responsible for performing a depth-first traversal and extracting the leaf node value.
- We start by popping the top node from the stack. If the node has left or right children, we push them onto the stack.
- If a node does not have left or right children (i.e., it is a leaf node), we return its value.
- The `dfs` function is called each time in the main `while` loop to retrieve the next leaf node from both trees.

### Complexity

#### Time Complexity:

- **DFS Traversal**: Both trees are traversed in a depth-first manner. In the worst case, each tree has `N` nodes (where `N` is the number of nodes in the tree), and we visit each node once. Thus, the DFS traversal for each tree takes `O(N)` time.
- **Comparison**: At each step, we compare the leaf nodes of both trees. Each comparison is done in constant time, `O(1)`.
- Therefore, the total time complexity is `O(N)`, where `N` is the total number of nodes in both trees.

#### Space Complexity:

- **Stack Space**: We use two stacks, `s1` and `s2`, which each store at most `O(N)` nodes during the DFS traversal.
- Therefore, the space complexity is `O(N)`.

### Conclusion

The solution efficiently compares the leaf nodes of two binary trees by performing a depth-first traversal on both trees simultaneously. The two stacks (`s1` and `s2`) allow us to traverse the trees in a memory-efficient manner, and the DFS function helps in extracting leaf nodes. By comparing the leaf nodes one-by-one, we ensure that the order and values match. This approach has a time complexity of `O(N)`, where `N` is the number of nodes in the trees, and a space complexity of `O(N)` due to the use of the stacks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/leaf-similar-trees/description/)

---
{{< youtube Nr8dbnL0_cM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
