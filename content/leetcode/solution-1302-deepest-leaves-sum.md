
+++
authors = ["grid47"]
title = "Leetcode 1302: Deepest Leaves Sum"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1302: Deepest Leaves Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ebJiQrgumP4"
youtube_upload_date="2023-06-03"
youtube_thumbnail="https://i.ytimg.com/vi/ebJiQrgumP4/maxresdefault.jpg"
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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()) {
            int sz = q.size();
            sum = 0;
            while(sz--) {
                sum += q.front()->val;
                TreeNode* x = q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return sum;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to calculate the sum of the values of the deepest (or lowest) leaves in a binary tree. A "leaf" node is a node that does not have any children. We need to identify the nodes at the deepest level of the tree and then calculate their total sum. If the tree is empty, the function should return `0`.

### Approach
The approach to solving this problem uses a **breadth-first search (BFS)** or **level-order traversal** strategy:
1. **Initialize BFS**: Begin the BFS traversal from the root node using a queue.
2. **Process Level by Level**: At each level, reset the sum to `0`, then calculate the sum of values for all nodes at that level. This ensures that the `sum` variable always contains the sum of the values of nodes from the current, deepest level being processed.
3. **Store the Deepest Level’s Sum**: By the end of the traversal, the `sum` variable holds the sum of the values of the nodes at the deepest level.
4. **Return the Result**: After finishing the traversal, return the sum of the deepest leaves.

### Code Breakdown (Step by Step)

1. **Class and Method Definition**:
   - We define a class `Solution` and a public method `deepestLeavesSum` that takes a `TreeNode` pointer `root` as input.

   ```cpp
   class Solution {
   public:
       int deepestLeavesSum(TreeNode* root) {
   ```

2. **Handle Edge Case**:
   - If the root is `NULL`, the function returns `0`, which represents an empty tree.

   ```cpp
           if(root == NULL) return 0;
   ```

3. **Initialize BFS**:
   - A queue `q` is created to perform the BFS. Push the root node into this queue. Initialize `sum` to store the sum of the deepest leaves.

   ```cpp
           queue<TreeNode*> q;
           q.push(root);
           int sum = 0;
   ```

4. **Level Order Traversal**:
   - Use a `while` loop to iterate through each level of the tree until the queue is empty.

   ```cpp
           while(!q.empty()) {
   ```

5. **Process Each Level**:
   - For each level:
     - Reset `sum` to `0` at the start of processing a level.
     - Determine the number of nodes in the current level using `sz = q.size()`.
     - Use a `while` loop to iterate through nodes of the current level, adding their values to `sum`.

   ```cpp
               int sz = q.size();
               sum = 0;
               while(sz--) {
                   sum += q.front()->val;
                   TreeNode* x = q.front();
                   q.pop();
   ```

6. **Add Child Nodes**:
   - For each node, if it has a left child, push it into the queue. If it has a right child, push that as well.

   ```cpp
                   if(x->left) q.push(x->left);
                   if(x->right) q.push(x->right);
               }
           }
   ```

7. **Return the Result**:
   - After processing all levels, the `sum` variable contains the sum of the values of nodes at the deepest level. Return this sum.

   ```cpp
           return sum;
       }
   };
   ```

### Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the tree. We visit each node exactly once during the BFS traversal.
- **Space Complexity**: \(O(W)\), where \(W\) is the maximum width of the tree (i.e., the maximum number of nodes at any level). This is the space required to store nodes in the queue.

### Conclusion
This implementation efficiently calculates the sum of the deepest leaves in a binary tree by leveraging the level-order traversal (BFS) approach. By resetting `sum` at the beginning of each level and summing values only for nodes at the current depth, this solution ensures that the `sum` variable ultimately contains the values of the nodes at the deepest level. This approach works well for all tree structures, including highly unbalanced trees, and guarantees that only nodes at the lowest depth are included in the final sum calculation. 

This code effectively balances simplicity and efficiency, providing a quick and readable solution to the problem of calculating the sum of the deepest leaves in a binary tree.

[`Link to LeetCode Lab`](https://leetcode.com/problems/deepest-leaves-sum/description/)

---
{{< youtube ebJiQrgumP4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
