
+++
authors = ["grid47"]
title = "Leetcode 687: Longest Univalue Path"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 687: Longest Univalue Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/687.webp"
youtube = "ZeBr9JMcjrU"
youtube_upload_date="2020-06-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZeBr9JMcjrU/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/687.webp" 
    alt="A tree where the longest univalue path is traced and softly glowing as it’s found."
    caption="Solution to LeetCode 687: Longest Univalue Path Problem"
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
    int maxi;
public:
    int longestUnivaluePath(TreeNode* root) {
        maxi = 0;
        if((root == NULL) || (root->left == NULL && root->right == NULL)  )
        return 0;
        dfs(root);
        return maxi;
    }

    int dfs(TreeNode *root) {
        if(root == NULL) return 0;
        int l = 0, r = 0;
        int lft = dfs(root->left);
        int rgt = dfs(root->right);
        if((root->left != NULL) && (root->left->val == root->val))
        l = lft;
        if((root->right != NULL) && (root->right->val == root->val))
        r = rgt;        

        maxi = max(maxi, l + r);
        return 1 + max(l, r);
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem at hand involves finding the longest univalue path in a binary tree. A univalue path is defined as a path where all nodes along the path have the same value. The task is to return the length of the longest path where the nodes have the same value. The path does not necessarily have to pass through the root, but it can go through any node in the tree.

### Approach:
To solve this problem, we use a **Depth-First Search (DFS)** approach. The main idea is to traverse the tree and calculate, for each node, the longest path that starts from that node and extends along its left and right subtrees while maintaining the same value. During this traversal, we also keep track of the maximum univalue path encountered so far.

We need to focus on two main things:
1. **DFS Traversal**: Recursively explore both left and right subtrees for each node.
2. **Path Calculation**: For each node, calculate the longest univalue path starting from the current node and extending through its left and right children.

### Code Breakdown (Step by Step):

#### 1. **TreeNode Definition**
The problem statement includes a predefined `TreeNode` structure:
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
Each `TreeNode` contains:
- `val`: The value of the node.
- `left`: A pointer to the left child of the node.
- `right`: A pointer to the right child of the node.

#### 2. **Main Solution Class**
```cpp
class Solution {
    int maxi;  // To store the maximum length of univalue path found.
public:
    int longestUnivaluePath(TreeNode* root) {
        maxi = 0;  // Initialize maxi to 0.
        if ((root == NULL) || (root->left == NULL && root->right == NULL))
            return 0;  // If the root is null or the tree has no child, return 0.
        dfs(root);  // Start DFS traversal to calculate the univalue paths.
        return maxi;  // Return the longest univalue path found.
    }
```
The function `longestUnivaluePath` initializes the `maxi` variable to track the longest path found. If the root is `NULL` or a leaf node (no children), the function returns `0` as there are no paths to explore. Otherwise, it calls the `dfs` function to start the depth-first search from the root and returns the result stored in `maxi`.

#### 3. **DFS Function**
```cpp
    int dfs(TreeNode *root) {
        if (root == NULL) return 0;  // Base case: if the node is NULL, return 0.
        int l = 0, r = 0;  // Initialize the lengths of the left and right paths.
        int lft = dfs(root->left);  // Recursive DFS for the left child.
        int rgt = dfs(root->right);  // Recursive DFS for the right child.
        
        // If the left child has the same value as the current node, extend the left path.
        if ((root->left != NULL) && (root->left->val == root->val))
            l = lft;  
        
        // If the right child has the same value as the current node, extend the right path.
        if ((root->right != NULL) && (root->right->val == root->val))
            r = rgt;

        // Update the maxi variable to store the maximum length of the univalue path.
        maxi = max(maxi, l + r);  
        
        // Return the longest univalue path starting from the current node.
        return 1 + max(l, r);  
    }
};
```
The `dfs` function works recursively to explore the tree. It computes the longest univalue path that starts from the current node and extends to its left or right subtree. Here’s how it works:

- **Base Case**: If the current node is `NULL`, return `0` as there’s no path to explore.
- **Recursive Case**: 
  - Call `dfs(root->left)` and `dfs(root->right)` to get the longest univalue paths starting from the left and right subtrees, respectively.
  - Check if the left or right children have the same value as the current node. If they do, extend the path from that child.
- **Update `maxi`**: After checking both left and right subtrees, calculate the total univalue path that passes through the current node by summing the lengths of the left and right paths (`l + r`), and update `maxi` with the maximum of its current value and the new path length.
- **Return the Length**: Return the length of the longest univalue path starting from the current node. Since the current node is part of the path, add `1` to the maximum of the left and right path lengths.

#### 4. **Final Output**
Once the DFS is complete, the longest univalue path will be stored in `maxi`, which is then returned by the `longestUnivaluePath` function.

### Complexity:

#### Time Complexity:
The time complexity of this solution is **O(N)**, where `N` is the number of nodes in the binary tree. The reason for this is that the DFS function visits each node exactly once, performing a constant amount of work per node.

#### Space Complexity:
The space complexity is **O(H)**, where `H` is the height of the tree. This is due to the recursive nature of DFS, where the maximum number of recursive calls that can be stacked is equal to the height of the tree. In the worst case (a skewed tree), this could be `O(N)`.

### Conclusion:
This solution effectively solves the problem of finding the longest univalue path in a binary tree using a depth-first search (DFS) approach. It efficiently computes the longest path where all nodes have the same value by recursively exploring the left and right subtrees of each node while keeping track of the maximum path length found. The time and space complexity are optimal for a tree traversal algorithm, making this solution both time-efficient and space-efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-univalue-path/description/)

---
{{< youtube ZeBr9JMcjrU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
