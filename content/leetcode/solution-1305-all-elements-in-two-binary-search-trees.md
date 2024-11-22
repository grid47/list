
+++
authors = ["grid47"]
title = "Leetcode 1305: All Elements in Two Binary Search Trees"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1305: All Elements in Two Binary Search Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Sorting","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "B97Hk1H2x2s"
youtube_upload_date="2020-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/B97Hk1H2x2s/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGDMgRih_MA8=&rs=AOn4CLC03GCnDEem80J52_RuXkBdpkuQfA"
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        vector<int> res;
        while(root1 || root2 || !st1.empty() || !st2.empty()) {
            while(root1) {
                st1.push(root1);
                root1 = root1->left;
            }
            while(root2) {
                st2.push(root2);
                root2 = root2->left;
            }
            if(st2.empty() || (!st1.empty() && st1.top()->val < st2.top()->val)) {
                root1 = st1.top();
                st1.pop();
                res.push_back(root1->val);
                root1 = root1->right;
            } else {
                root2 = st2.top();
                st2.pop();
                res.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
Given two binary search trees (BSTs), the task is to merge all of their elements into a single sorted list. This requires performing an in-order traversal on both trees to access their elements in ascending order, and then merging the results. The solution should have a time complexity close to \(O(m + n)\), where \(m\) and \(n\) are the number of nodes in each tree, and it should avoid using extra space beyond the necessary output list.

### Approach
This solution uses **in-order traversal** and **two stacks** to simulate iterators for each BST:
1. **In-Order Traversal**: Since BSTs have elements in sorted order when traversed in-order, this traversal helps us access each tree’s elements in ascending order.
2. **Stack-Based Iterative In-Order Traversal**: Instead of recursive traversal, this approach uses stacks to store nodes from each tree, simulating an in-order traversal. Each time the traversal visits a node, it either processes the node if it’s the smallest available node or goes to the next node’s right child.
3. **Simultaneous Traversal and Merge**: By pushing nodes from both trees onto their respective stacks, we can compare the current smallest elements of each tree. The smaller value is added to the result list, and the corresponding traversal continues.

### Code Breakdown (Step by Step)

1. **Class and Method Definition**:
   - We define a class `Solution` with a public method `getAllElements` that takes pointers to two tree roots, `root1` and `root2`, as input and returns a sorted list of all elements from both trees.

   ```cpp
   class Solution {
   public:
       vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
   ```

2. **Initialize Stacks and Result Vector**:
   - Two stacks, `st1` and `st2`, are initialized to store nodes for in-order traversal. A vector `res` is also initialized to store the sorted result.

   ```cpp
           stack<TreeNode*> st1, st2;
           vector<int> res;
   ```

3. **Loop until Traversal is Complete**:
   - The main `while` loop continues until both trees are completely traversed, which occurs when both `root1` and `root2` are `NULL` and both stacks are empty.

   ```cpp
           while(root1 || root2 || !st1.empty() || !st2.empty()) {
   ```

4. **Push All Left Children to Stack**:
   - For both `root1` and `root2`, a nested `while` loop pushes all left children onto their respective stacks. This simulates moving to the smallest element in each tree.

   ```cpp
               while(root1) {
                   st1.push(root1);
                   root1 = root1->left;
               }
               while(root2) {
                   st2.push(root2);
                   root2 = root2->left;
               }
   ```

5. **Merge Elements from Stacks**:
   - After both stacks are set up with left children, the code compares the top elements of each stack (the smallest unprocessed elements in each tree):
     - If `st2` is empty or `st1` has a smaller value than `st2`, the top element of `st1` is added to the result, and traversal continues to the right child of that element in `root1`.
     - Otherwise, the top element of `st2` is processed, added to the result, and traversal moves to its right child in `root2`.

   ```cpp
               if(st2.empty() || (!st1.empty() && st1.top()->val < st2.top()->val)) {
                   root1 = st1.top();
                   st1.pop();
                   res.push_back(root1->val);
                   root1 = root1->right;
               } else {
                   root2 = st2.top();
                   st2.pop();
                   res.push_back(root2->val);
                   root2 = root2->right;
               }
           }
   ```

6. **Return the Result**:
   - After processing all nodes, the result vector `res` contains all elements from both trees in sorted order.

   ```cpp
           return res;
       }
   };
   ```

### Complexity Analysis

- **Time Complexity**: \(O(m + n)\), where \(m\) and \(n\) are the number of nodes in `root1` and `root2`, respectively. Each node is visited exactly once, and the operations performed at each node are constant time.
- **Space Complexity**: \(O(h1 + h2)\), where \(h1\) and \(h2\) are the heights of the two trees. The stacks store at most `h1` and `h2` nodes, respectively, which is the space needed for a complete in-order traversal.

### Conclusion
This solution provides an efficient and scalable way to merge elements from two BSTs into a sorted list by simulating in-order traversal iteratively with two stacks. By managing left children and comparisons iteratively, the approach avoids recursion and minimizes space usage beyond the necessary result list. This algorithm is particularly effective for balanced BSTs, where the time complexity is close to linear, and is adaptable for trees with varying structures or heights.

[`Link to LeetCode Lab`](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/)

---
{{< youtube B97Hk1H2x2s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
