
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2008: Maximum Earnings From Taxi"
date = "2019-05-03"
description = "Solution to Leetcode 2008"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-earnings-from-taxi/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> rides;
    vector<long long> memo;
    int n;

    long long dp(int idx) {
        
        if(idx == rides.size()) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        long long ans = dp(idx + 1);
                
        
        int end = rides[idx][1];
        
        int l = idx + 1, r = rides.size() - 1;
        int pos = rides.size();
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(rides[mid][0] >= end) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
            
        ans = max(ans, dp(pos) + rides[idx][2]);        
        return memo[idx] = ans;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& ride) {
        this->n = n;
        rides = ride;
        sort(rides.begin(), rides.end());
        
        for(int i = 0; i < rides.size(); i++)
            rides[i][2] += rides[i][1] - rides[i][0];
        
        memo.resize(rides.size() + 1, -1);
        return dp(0);

    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

