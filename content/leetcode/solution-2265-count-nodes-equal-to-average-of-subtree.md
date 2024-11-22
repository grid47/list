
+++
authors = ["grid47"]
title = "Leetcode 2265: Count Nodes Equal to Average of Subtree"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2265: Count Nodes Equal to Average of Subtree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yg9A3yLTcsE"
youtube_upload_date="2022-05-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yg9A3yLTcsE/maxresdefault.webp"
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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        
        auto left = solve(root->left);
        int l_sum = left.first; // sum of nodes present in left sub tree
        int l_cnt = left.second; // no. of nodes present in left sub tree
        
        auto right = solve(root->right);
        int r_sum = right.first; // sum of nodes present in right sub tree
        int r_cnt = right.second; // no. of nodes present in left sub tree
        
        int sum = root->val + l_sum + r_sum;
        int cnt = l_cnt + r_cnt + 1;
        
        if(root->val == sum/cnt) ans++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given the root of a binary tree. Each node of the tree contains an integer value. The task is to find the number of nodes whose value is equal to the average of the values of the nodes in its subtree (including itself). The average of a node's subtree is defined as the sum of the values of all nodes in the subtree divided by the total number of nodes in the subtree.

You need to return the total count of nodes that satisfy the condition where the node's value is equal to the average of its subtree.

### Approach

To solve this problem, we can use a **post-order traversal** approach where:
1. We recursively compute the sum and the count of nodes in the subtree rooted at each node.
2. For each node, we check if the value of the node equals the average of its subtree. If it does, we increase the count of such nodes.
3. We return both the sum and the number of nodes in the subtree for each node to facilitate calculations at its parent node.

Here’s a more structured explanation of the approach:
1. **Subtree Information**: For each node, we need to calculate the sum of all nodes in its subtree and the total number of nodes in the subtree.
2. **Check Average**: After calculating the sum and count of nodes in the subtree, we compare the value of the node with the average of its subtree, which is computed as `sum / count`.
3. **Recursion**: We perform a post-order traversal of the tree, starting from the leaf nodes and moving upwards to the root. This ensures that when calculating the sum and count for a node, we already have the information for its left and right children.

### Code Breakdown (Step by Step)

#### Step 1: Define the TreeNode structure

The `TreeNode` structure is defined as:
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
This is a typical definition for a binary tree node, where `val` stores the value of the node, and `left` and `right` are pointers to its left and right child nodes, respectively.

#### Step 2: Initialize global variables

```cpp
int ans = 0;
```
- `ans` is initialized to `0` and will keep track of the number of nodes whose value is equal to the average of their respective subtrees.

#### Step 3: Define the recursive `solve` function

```cpp
pair<int, int> solve(TreeNode* root) {
    if (root == NULL) return {0, 0};
```
- The `solve` function takes a `TreeNode* root` as input and returns a pair of integers:
  - The first element of the pair represents the sum of node values in the subtree rooted at `root`.
  - The second element represents the number of nodes in the subtree.
- If `root` is `NULL` (base case), we return a pair `{0, 0}`, indicating that there are no nodes in the subtree and the sum is zero.

#### Step 4: Recursively solve for the left and right subtrees

```cpp
auto left = solve(root->left);
int l_sum = left.first; // sum of nodes in the left subtree
int l_cnt = left.second; // number of nodes in the left subtree

auto right = solve(root->right);
int r_sum = right.first; // sum of nodes in the right subtree
int r_cnt = right.second; // number of nodes in the right subtree
```
- We recursively call the `solve` function for the left and right children of the current node. We store the results for the left and right subtrees, which include the sum and count of nodes.

#### Step 5: Calculate the sum and count for the current subtree

```cpp
int sum = root->val + l_sum + r_sum;
int cnt = l_cnt + r_cnt + 1;
```
- The total sum for the subtree rooted at the current node is the sum of:
  - The value of the current node (`root->val`).
  - The sum of the left subtree (`l_sum`).
  - The sum of the right subtree (`r_sum`).
- The total count for the subtree is the sum of:
  - The count of nodes in the left subtree (`l_cnt`).
  - The count of nodes in the right subtree (`r_cnt`).
  - 1 (for the current node itself).

#### Step 6: Check if the node's value equals the average of its subtree

```cpp
if (root->val == sum / cnt) ans++;
```
- We check if the value of the current node (`root->val`) is equal to the average of its subtree, which is `sum / cnt`. If they are equal, we increment the `ans` variable, indicating that we found a node whose value equals the average of its subtree.

#### Step 7: Return the sum and count of the current subtree

```cpp
return {sum, cnt};
```
- After processing the current node, we return the sum and count of the nodes in the subtree rooted at `root`.

#### Step 8: Invoke the `solve` function and return the result

```cpp
int averageOfSubtree(TreeNode* root) {
    solve(root);
    return ans;
}
```
- The `averageOfSubtree` function is the entry point for the solution. It invokes the `solve` function on the root of the binary tree and returns the value of `ans`, which is the total number of nodes whose value equals the average of their subtree.

### Complexity

#### Time Complexity:
The time complexity of this solution is **O(n)**, where `n` is the number of nodes in the binary tree. This is because we visit each node exactly once during the post-order traversal, and at each node, we perform constant-time operations (sum and count calculations, comparisons, and increments).

#### Space Complexity:
The space complexity is **O(h)**, where `h` is the height of the binary tree. This is the space required for the recursion stack in the worst case. In the worst case, the tree is skewed (like a linked list), and the height is `n`. In the best case (balanced tree), the height is `log n`.

### Conclusion

This solution efficiently computes the number of nodes in the binary tree whose value is equal to the average of the nodes in their subtree. By leveraging a post-order traversal, the algorithm computes the sum and count of each subtree while checking if the current node satisfies the condition. The solution has a time complexity of **O(n)**, making it optimal for large trees, and uses a recursion stack with space complexity **O(h)**. This approach is both effective and efficient for solving the problem of subtree averages in binary trees.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/)

---
{{< youtube yg9A3yLTcsE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
