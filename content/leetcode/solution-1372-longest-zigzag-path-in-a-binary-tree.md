
+++
authors = ["grid47"]
title = "Leetcode 1372: Longest ZigZag Path in a Binary Tree"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1372: Longest ZigZag Path in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "hbzdyIlvBKI"
youtube_upload_date="2023-04-20"
youtube_thumbnail="https://i.ytimg.com/vi/hbzdyIlvBKI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/)

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
    map<TreeNode*, map<bool, int>> mp;
    int zigzag(TreeNode* root, bool dir) {
        if(!root) return -1;
        if(mp.count(root) && mp[root].count(dir)) return mp[root][dir];
        int ans = 0;
        if(dir)
            ans = 1 + zigzag(root->left, !dir);
        if(!dir)
            ans = 1 + zigzag(root->right, !dir);            
        return mp[root][dir] = ans;
    }
    
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        
        ans = max(ans, zigzag(root, 1));
        ans = max(ans, zigzag(root, 0));        
        
        if(root->left)
        longestZigZag(root->left);

        if(root->right)
        longestZigZag(root->right);

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1372.md" >}}
---
{{< youtube hbzdyIlvBKI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1376: Time Needed to Inform All Employees](https://grid47.xyz/leetcode/solution-1376-time-needed-to-inform-all-employees/) |
| --- |