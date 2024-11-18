
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
youtube = "cHwafswjTlE"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/501.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-mode-in-binary-search-tree/description/)
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/501.md" >}}
---
{{< youtube cHwafswjTlE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #508: Most Frequent Subtree Sum](https://grid47.xyz/leetcode/solution-508-most-frequent-subtree-sum/) |
| --- |
