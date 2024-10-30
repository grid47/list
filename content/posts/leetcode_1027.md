
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1027: Longest Arithmetic Subsequence"
date = "2022-01-08"
description = "Solution to Leetcode 1027"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<unordered_map<int, int>> mp;
        mp.resize(n);
        int res = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int d = nums[j] - nums[i];
                if(mp[j].count(d)) mp[i][d] = max(mp[i][d], mp[j][d] + 1);
                else mp[i][d] = max(mp[i][d], 2);
                res = max(mp[i][d], res);
            }
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

