
+++
authors = ["grid47"]
title = "Leetcode 508: Most Frequent Subtree Sum"
date = "2024-09-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 508: Most Frequent Subtree Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/508.webp"
youtube = "CvmRmzBQhu8"
youtube_upload_date="2023-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/CvmRmzBQhu8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-subtree-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/508.webp" 
    alt="A tree with sums at each subtree, and the most frequent subtree sum glowing brightly as it is discovered."
    caption="Solution to LeetCode 508: Most Frequent Subtree Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mx;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        map<int, int> mp;

        mx = 0;
        dfs(root, mp, ans);

        return ans;
    }
    
    int dfs(TreeNode* root, map<int, int>& mp, vector<int>& ans) {
        
        if (root == NULL) return 0;
        int res;
            
        if (root->left  == NULL && 
            root->right == NULL)
             { res = root->val; }
        else {
            int l = dfs(root->left , mp, ans);
            int r = dfs(root->right, mp, ans);
            res = l + r + root->val;
        }
        
        mp[res] += 1;
        
        if(mx < mp[res]) {
            ans.clear();
            ans.push_back(res);
            mx = mp[res];
        } else if(mx == mp[res]) {
            ans.push_back(res);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/508.md" >}}
---
{{< youtube CvmRmzBQhu8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #509: Fibonacci Number](https://grid47.xyz/leetcode/solution-509-fibonacci-number/) |
| --- |