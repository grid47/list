
+++
authors = ["grid47"]
title = "Leetcode 971: Flip Binary Tree To Match Preorder Traversal"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 971: Flip Binary Tree To Match Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6L25Q-42OXA"
youtube_upload_date="2021-03-29"
youtube_thumbnail="https://i.ytimg.com/vi/6L25Q-42OXA/maxresdefault.jpg"
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
    vector<int> res;
    int i = 0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> fail = {-1};
        return dfs(root, voyage)? res: fail;
    }

    bool dfs(TreeNode* node, vector<int> &voyage) {
        if(node == NULL) return true;
        if(node->val != voyage[i++]) return false;
        if(node->left != NULL && node->left->val != voyage[i]) {
            res.push_back(node->val);
            return  dfs(node->right, voyage) && dfs(node->left, voyage);
        }
        return  dfs(node->left, voyage) && dfs(node->right, voyage);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine whether we can flip some of the nodes of a binary tree so that the tree’s preorder traversal matches a given voyage array. If it is possible, the task is to return the list of nodes that need to be flipped to achieve this. If it is not possible, we need to return `[-1]`. The tree is represented as a binary tree, and the voyage is an array of integers representing the desired preorder traversal of the tree. The flip operation allows us to swap the left and right child nodes of any tree node.

### Approach

The solution to this problem involves a depth-first search (DFS) approach to traverse the binary tree and check whether we can match the preorder traversal `voyage` while keeping track of the nodes that need to be flipped to achieve the desired traversal. The steps to approach this problem are as follows:

1. **Start from the root of the tree**: We initiate a DFS traversal starting from the root of the binary tree.
2. **Matching node values with the voyage**: During the DFS, at each node, we check if the current node’s value matches the value in the `voyage` array. If the value matches, we proceed to the next node in the `voyage`. If not, we return `false`.
3. **Identifying a required flip**: If the left child node exists and its value does not match the next value in the `voyage`, we recognize that a flip is needed. We then swap the left and right children for the current node, record the node as flipped in the result list, and continue the DFS.
4. **Return the result**: Once the traversal is complete, we check if we successfully matched the entire `voyage`. If so, we return the list of flipped nodes. If any mismatch occurs during the traversal, we return `[-1]`.

The problem is solved in a recursive manner by using the DFS technique, making use of an auxiliary variable `i` to keep track of the current position in the `voyage`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
    vector<int> res;
    int i = 0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> fail = {-1};
        return dfs(root, voyage) ? res : fail;
    }
```
1. **Function Declaration**:
   - The function `flipMatchVoyage` is declared with two arguments: `root` (the root node of the binary tree) and `voyage` (the array representing the desired preorder traversal).
   - We initialize an empty vector `res` to store the flipped nodes. We also initialize `i = 0`, which will serve as an index to track the current position in the `voyage`.
   - If the DFS traversal returns `true`, meaning the `voyage` is successfully matched with the tree’s preorder traversal, the function returns the `res` vector containing the flipped nodes. If not, it returns `[-1]`, indicating that it is not possible to achieve the desired traversal.

```cpp
    bool dfs(TreeNode* node, vector<int> &voyage) {
        if(node == NULL) return true;
```
2. **DFS Traversal**:
   - The DFS function is defined to traverse the binary tree.
   - The base case checks if the current node is `NULL`. If it is, it returns `true` since there is nothing to flip or match at a `NULL` node.

```cpp
        if(node->val != voyage[i++]) return false;
```
3. **Matching Node Value with Voyage**:
   - For each node in the tree, we compare its value (`node->val`) with the value in the `voyage` at index `i`. 
   - If the value does not match, we return `false`, as this means the tree cannot match the desired preorder traversal. 
   - We also increment `i` after the comparison to move to the next index in the `voyage`.

```cpp
        if(node->left != NULL && node->left->val != voyage[i]) {
```
4. **Check for Flip Requirement**:
   - If the left child of the current node exists (`node->left != NULL`), we check whether the left child’s value matches the next value in the `voyage` at index `i`. If it does not match, we need to flip the left and right children to continue matching the `voyage`.
   - If a flip is required, we enter the block of code that swaps the left and right children and adds the current node’s value to the `res` vector.

```cpp
            res.push_back(node->val);
            return dfs(node->right, voyage) && dfs(node->left, voyage);
```
5. **Flip the Node**:
   - We push the current node’s value into the result vector `res`, indicating that this node needs to be flipped.
   - After the flip, we recursively call `dfs` on the right child first (`node->right`), followed by the left child (`node->left`). This ensures that we are flipping the children nodes and then continuing the DFS traversal for both sides.

```cpp
        return dfs(node->left, voyage) && dfs(node->right, voyage);
    }
```
6. **Recursive DFS Without Flip**:
   - If no flip is needed (i.e., the left child’s value matches the next value in the `voyage`), we recursively call `dfs` on the left child (`node->left`) first, and then the right child (`node->right`). This is the standard preorder traversal (left, right).

```cpp
};
```
7. **End of Function**:
   - The DFS function ends, and control is returned to the main function `flipMatchVoyage`.

### Complexity

- **Time Complexity**: 
  - The time complexity of this algorithm is **O(n)**, where `n` is the number of nodes in the binary tree. In the worst case, the algorithm performs a DFS traversal of all the nodes in the tree, visiting each node once. Each comparison and operation inside the DFS function takes constant time.

- **Space Complexity**:
  - The space complexity is **O(h)**, where `h` is the height of the tree. This is because the recursive DFS function uses a call stack that can grow up to the height of the tree in the worst case. The additional space used by the result vector `res` is proportional to the number of flipped nodes, but this is at most `n`, where `n` is the number of nodes.

### Conclusion

This solution effectively solves the problem by performing a depth-first search (DFS) on the binary tree while keeping track of the nodes that need to be flipped in order to match the desired preorder traversal given in the `voyage`. The approach ensures that only the necessary nodes are flipped, and it efficiently checks whether the tree’s preorder traversal can be transformed to match the `voyage`. The solution uses recursion, a common technique for tree traversal problems, and ensures the result is returned in the form of a vector containing the flipped nodes. If the transformation is not possible, it correctly returns `[-1]`.

[`Link to LeetCode Lab`](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/)

---
{{< youtube 6L25Q-42OXA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
