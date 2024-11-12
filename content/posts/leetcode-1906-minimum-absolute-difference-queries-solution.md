
+++
authors = ["grid47"]
title = "Leetcode 1906: Minimum Absolute Difference Queries"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1906: Minimum Absolute Difference Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-difference-queries/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {

        int prefix[100001][101] = {}, cnt[101] = {};
        
        int n = nums.size(), m = q.size();
        
        for(int i = 0; i < n; i++) {
            cnt[nums[i]]++;
            for(int j = 1; j < 101; j++) prefix[i + 1][j] = cnt[j];
        }
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            int l = q[i][0], r = q[i][1];
            int frq[101] = {};
            for(int j = 1; j < 101; j++) frq[j] = prefix[r + 1][j] - prefix[l][j];
            int prv = -1, mn = INT_MAX;
            for(int j = 1; j < 101; j++) {
                if(frq[j] == 0) continue;
                if(prv != -1 && j - prv < mn) mn = j - prv;
                prv = j;
            }
            ans.push_back(mn == INT_MAX? -1: mn);
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1906.md" >}}
---
{{< youtube H_Nrt9dOwLM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1910: Remove All Occurrences of a Substring](https://grid47.xyz/posts/leetcode-1910-remove-all-occurrences-of-a-substring-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
