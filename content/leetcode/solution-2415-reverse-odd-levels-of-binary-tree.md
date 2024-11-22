
+++
authors = ["grid47"]
title = "Leetcode 2415: Reverse Odd Levels of Binary Tree"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2415: Reverse Odd Levels of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iR3r4iEIDZo"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/iR3r4iEIDZo/maxresdefault.webp"
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> vals;
        int level = 0;

        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for(int i = 0; i < sz; i++)  {
                TreeNode* node = q.front(); q.pop();
                if(level %2) node->val= vals[sz- i - 1];
                if(node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }

                if(node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            vals = temp;
            level++;
        }
        return root;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to reverse the values of all nodes at odd levels of a binary tree. The root node is considered at level 0, and the subsequent levels increase as we move down the tree. A level is considered odd if it is an odd-numbered level (e.g., level 1, 3, 5, etc.), and even if it is an even-numbered level (e.g., level 0, 2, 4, etc.). The task is to reverse the values of all nodes at odd levels while keeping the structure of the tree intact.

### Approach

To solve this problem, the idea is to perform a level-order traversal (also known as breadth-first search) on the binary tree and process the nodes in each level. During the traversal:
1. We keep track of the nodes at each level using a queue.
2. We reverse the values of the nodes at odd levels while leaving the values at even levels unchanged.
3. We use a helper vector `vals` to store the values of nodes at odd levels temporarily, which will be used to reverse the values at the corresponding level.
4. After completing the traversal, the tree is modified such that only the nodes at odd levels are reversed.

### Code Breakdown (Step by Step)

#### 1. TreeNode Definition

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
- The `TreeNode` struct defines the basic structure of a binary tree node. Each node has an integer value `val`, and two pointers `left` and `right`, pointing to the left and right child nodes, respectively. The default constructor initializes a node with a value of `0`, and the parameterized constructors initialize the node with a given value and optional left and right child nodes.

#### 2. Function Signature

```cpp
TreeNode* reverseOddLevels(TreeNode* root) {
    if(!root) return root;
```
- The function `reverseOddLevels` accepts a pointer to the root of the binary tree and returns a pointer to the root of the modified tree. If the root is `nullptr`, the function immediately returns `nullptr` since there is nothing to process.

#### 3. Initialization of Variables

```cpp
queue<TreeNode*> q;
q.push(root);
vector<int> vals;
int level = 0;
```
- A queue `q` is initialized to perform level-order traversal.
- The root of the tree is added to the queue.
- An empty vector `vals` is used to temporarily store the values of the nodes at each level.
- The `level` variable is initialized to `0` to track the current level of the tree during the traversal.

#### 4. Level-Order Traversal

```cpp
while(!q.empty()) {
    int sz = q.size();
    vector<int> temp;
```
- The `while` loop continues as long as there are nodes in the queue, ensuring that we process every level of the tree.
- `sz` stores the number of nodes at the current level. A new vector `temp` is used to store the values of the nodes at the current level.

#### 5. Processing Each Node in the Level

```cpp
for(int i = 0; i < sz; i++)  {
    TreeNode* node = q.front(); q.pop();
```
- The `for` loop iterates over each node at the current level.
- `node` is set to the node at the front of the queue, and the node is removed from the queue using `q.pop()`.

#### 6. Reversing Values at Odd Levels

```cpp
if(level %2) node->val = vals[sz - i - 1];
```
- If the current level is odd (`level % 2` evaluates to `true`), the value of the node is updated. We set the node's value to the corresponding value from the `vals` vector, which is the reversed order of values at the current level.
- The `vals[sz - i - 1]` expression is used to access the reversed value, as we are reversing the order of the values in `vals`.

#### 7. Storing Child Node Values

```cpp
if(node->left) {
    q.push(node->left);
    temp.push_back(node->left->val);
}

if(node->right) {
    q.push(node->right);
    temp.push_back(node->right->val);
}
```
- If the node has a left child, the left child is added to the queue and its value is added to the `temp` vector.
- Similarly, if the node has a right child, the right child is added to the queue and its value is added to the `temp` vector.

#### 8. Updating the `vals` Vector

```cpp
vals = temp;
level++;
```
- After processing all nodes at the current level, the `vals` vector is updated to `temp`, which contains the values of the nodes at the next level.
- The `level` variable is incremented to move to the next level in the next iteration.

#### 9. Return the Root of the Modified Tree

```cpp
return root;
```
- After the traversal is complete and the values of the nodes at odd levels have been reversed, the root of the modified tree is returned.

### Complexity

#### Time Complexity:
- The time complexity of this algorithm is \( O(N) \), where `N` is the total number of nodes in the binary tree. This is because we perform a level-order traversal, visiting each node exactly once.

#### Space Complexity:
- The space complexity is \( O(N) \), where `N` is the total number of nodes in the tree. This space is used by the queue `q` for storing nodes at each level and the `vals` vector to temporarily store the values at each level.

### Conclusion

This solution efficiently solves the problem by using a breadth-first traversal approach. It processes each level of the binary tree, reverses the values at odd levels, and maintains the tree structure. The algorithm has optimal time and space complexity, making it suitable for large binary trees.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/)

---
{{< youtube iR3r4iEIDZo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
