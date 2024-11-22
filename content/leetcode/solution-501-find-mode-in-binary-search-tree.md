
+++
authors = ["grid47"]
title = "Leetcode 501: Find Mode in Binary Search Tree"
date = "2024-09-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 501: Find Mode in Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/501.webp"
youtube = "cHwafswjTlE"
youtube_upload_date="2019-05-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/cHwafswjTlE/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/501.webp" 
    alt="A glowing tree with nodes lighting up to highlight the mode, with the mode’s value softly radiating."
    caption="Solution to LeetCode 501: Find Mode in Binary Search Tree Problem"
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
public:
    int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
    vector<int> res;

    vector<int> findMode(TreeNode *root)
    {
        inorderTraversal(root);
        return res;
    }

    void inorderTraversal(TreeNode *root)
    {
        if (root == NULL) return; // Stop condition
        inorderTraversal(root->left); // Traverse left subtree
        if (precursor == root->val) currFreq++;
        else currFreq = 1;
        if (currFreq > maxFreq)
        {// Current node value has higher frequency than any previous visited
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        }
        else if (currFreq == maxFreq)
        {// Current node value has a frequency equal to the highest of previous visited
            res.push_back(root->val);
        }
        precursor = root->val; // Update the precursor
        inorderTraversal(root->right); // Traverse right subtree
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the mode(s) in a binary search tree (BST), where the mode is defined as the value(s) that appear most frequently. Given the properties of a BST—where left nodes are smaller than the root and right nodes are larger—finding the mode can be efficiently achieved by leveraging an in-order traversal, which visits nodes in ascending order. The challenge here is to traverse the tree and track frequencies without extra space for storing all nodes, resulting in an optimal, in-place solution.

### Approach

This solution employs in-order traversal to visit nodes in ascending order. As we traverse each node, we compare it with the previously visited node to determine if the current value is the same. If it is, we increment the frequency count. If not, we reset the count for the new value. By maintaining the maximum frequency encountered, we can efficiently update the result list whenever a new mode or another equally frequent value is found. Here’s a detailed breakdown of each component:

1. **In-Order Traversal**:
   - In-order traversal is ideal for BSTs because it visits nodes in a sorted order, allowing us to detect sequences of identical values.
   - During traversal, if the current node’s value matches the previously visited node’s value, we increment the frequency counter. If not, we reset the counter to 1.

2. **Tracking Frequencies**:
   - Three main variables help track the frequency: `maxFreq` (to store the highest frequency encountered), `currFreq` (current frequency of the value being checked), and `precursor` (the value of the last visited node).
   - When `currFreq` surpasses `maxFreq`, we clear the result vector `res` and add the current node’s value as the new mode. If `currFreq` equals `maxFreq`, we add the current node’s value to `res` since it has the same highest frequency.

3. **Edge Case Handling**:
   - If the BST is empty (`root == NULL`), we immediately return an empty result vector, as there are no nodes to process.

### Code Breakdown (Step by Step)

Here is a breakdown of the code:

1. **Data Member Initialization**:
   ```cpp
   int maxFreq = 0, currFreq = 0, precursor = INT_MIN;
   vector<int> res;
   ```
   - `maxFreq`: Tracks the maximum frequency of any node value encountered so far.
   - `currFreq`: Tracks the frequency of the current node value.
   - `precursor`: Holds the last visited node’s value, initialized to `INT_MIN` as a placeholder.
   - `res`: Stores the result modes (values that appear with the highest frequency).

2. **Main Function (`findMode`)**:
   ```cpp
   vector<int> findMode(TreeNode *root) {
       inorderTraversal(root);
       return res;
   }
   ```
   - `findMode` serves as the main function that initiates the in-order traversal of the BST.
   - After traversal, it returns the result vector `res` containing the modes of the tree.

3. **Recursive In-Order Traversal (`inorderTraversal`)**:
   ```cpp
   void inorderTraversal(TreeNode *root) {
       if (root == NULL) return;
       inorderTraversal(root->left);
       if (precursor == root->val) currFreq++;
       else currFreq = 1;
       if (currFreq > maxFreq) {
           res.clear();
           maxFreq = currFreq;
           res.push_back(root->val);
       }
       else if (currFreq == maxFreq) {
           res.push_back(root->val);
       }
       precursor = root->val;
       inorderTraversal(root->right);
   }
   ```
   - **Base Case**: If the current node is `NULL`, the function returns immediately, ending recursion for that path.
   - **Left Subtree Traversal**: The function first recursively traverses the left subtree, consistent with in-order traversal.
   - **Frequency Check**:
     - If the current node’s value equals `precursor`, it means the same value has been encountered consecutively, so `currFreq` is incremented.
     - If the value differs, `currFreq` is reset to 1 for this new value.
   - **Updating Results**:
     - If `currFreq` exceeds `maxFreq`, we clear the `res` vector (as a new mode with a higher frequency has been found), update `maxFreq` to `currFreq`, and add the current node’s value to `res`.
     - If `currFreq` matches `maxFreq`, the current node’s value has the same frequency as previous modes, so it’s added to `res`.
   - **Right Subtree Traversal**: After processing the current node, we traverse the right subtree to complete the in-order traversal.

### Complexity Analysis

1. **Time Complexity**:
   - **O(n)**: We visit each node exactly once during the in-order traversal, where `n` is the number of nodes in the BST.

2. **Space Complexity**:
   - **O(h)**: The recursion stack requires space proportional to the height of the tree, which is `O(log n)` for a balanced BST and `O(n)` for a skewed BST.

### Conclusion

This solution leverages in-order traversal to efficiently find the modes in a BST. By maintaining a frequency count of consecutive values, we avoid the need for extra storage or additional traversals. The approach is both time-efficient and space-optimized for BST structures, with performance largely determined by tree height. This implementation is ideal for cases where memory constraints are tight, as it only uses minimal extra space for tracking modes and frequencies.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-mode-in-binary-search-tree/description/)

---
{{< youtube cHwafswjTlE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
