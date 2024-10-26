
+++
authors = ["Yasir"]
title = "Leetcode 508: Most Frequent Subtree Sum"
date = "2023-06-07"
description = "Solution to Leetcode 508"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-subtree-sum/description/)

---

**Code:**

{{< highlight html >}}
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

