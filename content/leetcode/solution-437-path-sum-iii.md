
+++
authors = ["grid47"]
title = "Leetcode 437: Path Sum III"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 437: Path Sum III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/437.webp"
youtube = "Vam9gldRapY"
youtube_upload_date="2020-08-08"
youtube_thumbnail="https://i.ytimg.com/vi/Vam9gldRapY/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGIgZSgsMA8=&rs=AOn4CLByu4Pnq9YHL4GumLlrHVQp65TWqQ"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/437.webp" 
    alt="A tree with nodes lighting up, showing the path sum from a root node to the leaves, highlighting valid paths."
    caption="Solution to LeetCode 437: Path Sum III Problem"
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
    int cnt = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return cnt;
    }
    
    void dfs(TreeNode* root, long sum) {
        if(root == NULL) return;

        test(root, sum);
        dfs(root->left,  sum);
        dfs(root->right, sum);

    }
    
    void test(TreeNode* root, long sum) {
        if  (root     == NULL) return;
        if  (root->val == sum ) cnt++;
        test(root->left,  sum - root->val);
        test(root->right, sum - root->val);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the number of paths in a binary tree where the sum of the node values equals a given target sum. A path can start and end at any node in the tree, and the path can go downwards to any child node. Specifically, we need to count how many paths in the binary tree sum up to the given target sum.

### Approach

To solve this problem, we need to break it down into two main parts:

1. **Recursive Search for Paths**: The main goal is to traverse the tree and, for each node, look for paths that sum to the target value.
2. **Backtracking with Path Sum Calculation**: For each node, we recursively check all possible paths that can start from that node, both through the left and right subtrees. Every time we encounter a node whose value matches the target sum, we increase the count.

The key insight here is to utilize depth-first search (DFS) to traverse the binary tree and backtrack on each node to check all possible paths for the sum. We'll recursively explore each node and attempt to find paths by subtracting the node value from the target sum. If we reach a node where the remaining sum is zero, we know we've found a valid path.

### Code Breakdown (Step by Step)

#### Step 1: The `pathSum` Function

```cpp
int pathSum(TreeNode* root, int sum) {
    dfs(root, sum);
    return cnt;
}
```

- This function is the entry point for counting the paths. It starts by calling the `dfs` (depth-first search) function, which will recursively explore the tree.
- The variable `cnt` is a global counter that will keep track of how many paths satisfy the condition of summing up to the target value (`sum`).
  
#### Step 2: The `dfs` Function

```cpp
void dfs(TreeNode* root, long sum) {
    if(root == NULL) return;
    test(root, sum);
    dfs(root->left, sum);
    dfs(root->right, sum);
}
```

- The `dfs` function is a recursive function that traverses the entire binary tree.
- The base case is when `root` is `NULL`. In that case, we simply return as there's no path to process.
- The function first calls the `test` function, which checks whether there is a path starting at the current node that sums to the target `sum`.
- Then, the function recursively calls `dfs` on the left and right children of the current node.

#### Step 3: The `test` Function

```cpp
void test(TreeNode* root, long sum) {
    if (root == NULL) return;
    if (root->val == sum) cnt++;
    test(root->left, sum - root->val);
    test(root->right, sum - root->val);
}
```

- The `test` function checks if there is a path starting from the given node that matches the target `sum`.
- If the current node's value is equal to the target `sum`, it means we've found a valid path, and we increment the `cnt` variable.
- The function then recursively explores the left and right children of the current node, adjusting the target sum by subtracting the current node's value from the remaining sum. This ensures we're looking for paths that subtract the node's value from the target sum at each step.
  
#### Recursion and Backtracking

- The `dfs` function performs a depth-first traversal of the tree, checking each node for valid paths.
- The `test` function performs backtracking, checking if the current path from a node to its descendants sums to the target value.
  
By calling `dfs(root, sum)` for the root node, the algorithm explores all paths in the tree, checking for paths starting at every node, both from the left and right subtrees.

### Complexity

#### Time Complexity:
- The time complexity of this solution is `O(n^2)`, where `n` is the number of nodes in the binary tree.
- The `dfs` function explores every node in the tree, and for each node, the `test` function is called. The `test` function checks the path sum for each node, which requires exploring the entire path from that node to its descendants. As a result, this leads to a quadratic time complexity.

#### Space Complexity:
- The space complexity is `O(h)`, where `h` is the height of the binary tree, due to the recursive stack. In the worst case, if the tree is skewed, the height will be `n`, leading to a space complexity of `O(n)`. For balanced trees, the space complexity will be `O(log n)`.

### Conclusion

This solution efficiently counts the number of valid paths in a binary tree where the sum of node values equals the given target sum. By using a depth-first search (DFS) approach and backtracking with the `test` function, the algorithm explores all potential paths in the tree and checks if they sum up to the target.

Although the time complexity is `O(n^2)`, which can be slow for large trees, the solution works well for smaller to moderately sized trees and demonstrates a clear and recursive approach to solving path sum problems. Additionally, optimizations could be made to improve the time complexity, such as using dynamic programming or caching, though this solution provides a simple yet effective approach to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/path-sum-iii/description/)

---
{{< youtube Vam9gldRapY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
