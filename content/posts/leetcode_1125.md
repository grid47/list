
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1125: Smallest Sufficient Team"
date = "2021-10-01"
description = "Solution to Leetcode 1125"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-sufficient-team/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        unordered_map<string, int> mp;
        for(int i = 0; i < req.size(); i++)
            mp[req[i]] = i;
        
        int n = req.size();
        
        unordered_map<int, vector<int>> dp;        
        dp.reserve(1 << n);
        dp[0] = {};

        for(int i = 0; i < people.size(); i++) {
            int m = 0;
            for(string x: people[i]) {
                m |= (1 << mp[x]);
            }
            
            for(auto it = dp.begin(); it != dp.end(); it++) {
                int comb = m | it->first;
                if(!dp.count(comb) || (dp[comb].size() > 1 + dp[it->first].size())) {
                    dp[comb] = it->second;
                    dp[comb].push_back(i);
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

