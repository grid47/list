
+++
authors = ["grid47"]
title = "Leetcode 515: Find Largest Value in Each Tree Row"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 515: Find Largest Value in Each Tree Row in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/515.webp"
youtube = "0EVQluJY224"
youtube_upload_date="2021-02-01"
youtube_thumbnail="https://i.ytimg.com/vi/0EVQluJY224/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/515.webp" 
    alt="A tree with rows of values, each row highlighted with the largest value softly glowing."
    caption="Solution to LeetCode 515: Find Largest Value in Each Tree Row Problem"
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
    vector<int> largestValues(TreeNode* root) {
            queue<TreeNode*> q;
        vector<int> res;        
        if(!root) return res;
        q.push(root);
        int mx;

        while(!q.empty()) {
            int sz = q.size();
            mx = INT_MIN;
            while(sz-- > 0) {
                root = q.front();
                q.pop();
                mx = max(mx, root->val);                
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);                
            }
            res.push_back(mx);
        }
        return res;    
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/515.md" >}}
---
{{< youtube 0EVQluJY224 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #516: Longest Palindromic Subsequence](https://grid47.xyz/leetcode/solution-516-longest-palindromic-subsequence/) |
| --- |