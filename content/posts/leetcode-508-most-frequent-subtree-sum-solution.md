
+++
authors = ["grid47"]
title = "Leetcode 508: Most Frequent Subtree Sum"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 508: Most Frequent Subtree Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-subtree-sum/description/)

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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #509: Fibonacci Number](https://grid47.xyz/posts/leetcode-509-fibonacci-number-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}