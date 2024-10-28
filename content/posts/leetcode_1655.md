
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1655: Distribute Repeating Integers"
date = "2020-04-18"
description = "Solution to Leetcode 1655"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distribute-repeating-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int m;
    vector<int> q, frq, cost;
    vector<vector<int>> memo;    

    bool dp(int idx, int msk) {
        if(msk == ((1 << m) - 1)) return true;
        if(idx == frq.size()) return false;

        if(memo[idx][msk] != -1) return memo[idx][msk];
        
        for(int i = msk + 1; i < (1 << m); i++) {
            if((msk != (msk & i))) continue;
            if(frq[idx] >= (cost[i] - cost[msk])) {
                if(dp(idx + 1, i)) return memo[idx][msk]= true;
            }
        }

        return memo[idx][msk] = dp(idx + 1, msk);
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        q = quantity;
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;

        for(auto [key, val] : mp) frq.push_back(val);        
        
        m = q.size();
        cost.resize(1 << m, 0);
        for(int msk = 0; msk < (1 << m); msk++) {
            int net = 0;
            for(int i = 0; i < m; i++)
                if(msk & (1 << i)) net += q[i];
            cost[msk] = net;
        }
        
        memo.resize(frq.size(), vector<int>(1025, -1));
        // return true;
        return dp(0, 0);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

