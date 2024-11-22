
+++
authors = ["grid47"]
title = "Leetcode 1609: Even Odd Tree"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1609: Even Odd Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FkNWN1Fj_TY"
youtube_upload_date="2024-02-29"
youtube_thumbnail="https://i.ytimg.com/vi/FkNWN1Fj_TY/maxresdefault.jpg"
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool isEI = true;
        // increasing - I
        // even - E
        while(!q.empty()) {
            int sz = q.size();
            int prv = isEI? INT_MIN : INT_MAX;
            while(sz--) {
                TreeNode* n = q.front();
                q.pop();
                if(isEI) {
                    if(n->val % 2 == 0) return false;
                    if(n->val <= prv)    return false;
                } else {
                    if(n->val % 2 == 1) return false;                    
                    if(n->val >= prv)    return false;
                }
                prv = n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            isEI = !isEI;
        }

        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine whether a binary tree satisfies the conditions of an "Even-Odd Tree." An Even-Odd Tree has the following properties:

1. The tree must alternate between even and odd levels. The root node is considered level 0 (even).
2. At even levels (0, 2, 4, ...), the node values must be odd and strictly increasing from left to right.
3. At odd levels (1, 3, 5, ...), the node values must be even and strictly decreasing from left to right.

Given a binary tree represented by its root node, the objective is to return `true` if the tree satisfies the Even-Odd conditions; otherwise, return `false`.

### Approach

To solve the problem, we will use a level-order traversal (BFS) of the tree. During this traversal, we will maintain a boolean flag to indicate whether we are currently at an even level or an odd level. For each level, we will validate the conditions for either the even or odd levels based on the current flag state.

The steps for the algorithm are as follows:

1. **Initialize a Queue**: We will use a queue to facilitate the level-order traversal of the tree.
2. **Track Level Information**: We need a boolean flag to indicate whether the current level is even or odd.
3. **Process Each Level**: For each level:
   - Check the node values according to the Even-Odd conditions:
     - For even levels, ensure all values are odd and strictly increasing.
     - For odd levels, ensure all values are even and strictly decreasing.
   - Update the flag for the next level.
4. **Return the Result**: After processing all levels, if all conditions are satisfied, return `true`; otherwise, return `false`.

### Code Breakdown (Step by Step)

Here’s a detailed explanation of the provided code:

```cpp
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
    bool isEvenOddTree(TreeNode* root) {
```
- The code begins with a standard definition for a binary tree node using the `TreeNode` struct.
- The `Solution` class contains a public method `isEvenOddTree`, which accepts the root node of the tree and returns a boolean indicating whether the tree meets the Even-Odd criteria.

```cpp
        queue<TreeNode*> q;
        q.push(root);
```
- We create a queue `q` and push the root node onto it to initiate the level-order traversal.

```cpp
        bool isEI = true; // Flag to track whether we are at an even (true) or odd (false) level.
```
- We initialize a boolean variable `isEI` to `true`, indicating that we start at level 0 (even).

```cpp
        while(!q.empty()) {
            int sz = q.size();
            int prv = isEI ? INT_MIN : INT_MAX; // Previous node's value for comparison
```
- We enter a loop that continues until the queue is empty. At the beginning of each iteration, we record the size of the current level (`sz`) and set the initial value of `prv` based on the current level being even or odd.

```cpp
            while(sz--) {
                TreeNode* n = q.front();
                q.pop();
```
- We then enter another loop that processes each node at the current level. We retrieve the front node from the queue and remove it.

```cpp
                if(isEI) {
                    if(n->val % 2 == 0) return false; // Check if value is even
                    if(n->val <= prv) return false;   // Check if value is strictly increasing
                } else {
                    if(n->val % 2 == 1) return false; // Check if value is odd
                    if(n->val >= prv) return false;   // Check if value is strictly decreasing
                }
```
- Inside this inner loop, we validate the node value according to the Even-Odd conditions:
  - If on an even level, the value must be odd and strictly greater than the previous value.
  - If on an odd level, the value must be even and strictly less than the previous value.

```cpp
                prv = n->val; // Update the previous value to the current node's value
```
- We update `prv` to the current node’s value for the next comparison.

```cpp
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            isEI = !isEI; // Toggle the flag for the next level
        }
```
- If the current node has a left or right child, we push them onto the queue for processing in the next level.
- After processing all nodes in the current level, we toggle `isEI` to switch to the next level.

```cpp
        return true; // All conditions satisfied
    }
};
```
- Finally, if all levels are processed without returning `false`, we return `true`, indicating that the tree satisfies the Even-Odd conditions.

### Complexity

- **Time Complexity**: 
  - The time complexity of this solution is \(O(N)\), where \(N\) is the number of nodes in the binary tree. We visit each node exactly once.

- **Space Complexity**: 
  - The space complexity is \(O(W)\), where \(W\) is the maximum width of the tree. In the worst case (for a complete binary tree), this could be \(O(N)\).

### Conclusion

The provided implementation effectively determines whether a binary tree is an Even-Odd Tree by using level-order traversal to check the required conditions for even and odd levels. The approach is efficient, with a linear time complexity relative to the number of nodes in the tree.

**Key Aspects of the Solution**:
1. **Level-Order Traversal**: Utilizes a queue to traverse the tree level by level, making it easy to validate the conditions for each level.
2. **Condition Checking**: Clearly checks conditions based on the current level's parity, ensuring strict adherence to the Even-Odd Tree rules.
3. **Toggle Mechanism**: Efficiently toggles between even and odd levels with a simple boolean flag, reducing complexity and enhancing clarity.

In summary, this implementation provides a concise and efficient solution to the Even-Odd Tree problem, demonstrating the utility of BFS in tree-related challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/even-odd-tree/description/)

---
{{< youtube FkNWN1Fj_TY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
