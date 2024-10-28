
+++
authors = ["Yasir"]
title = "Leetcode 1824: Minimum Sideway Jumps"
date = "2019-11-01"
description = "Solution to Leetcode 1824"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sideway-jumps/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> memo;
    int dp(int cur, int idx, vector<int> &obs) {

        if(idx == obs.size()) return 0;
        if(memo[cur][idx] != -1) return memo[cur][idx];
        if(obs[idx] == cur) return INT_MAX - 1;
        
        int ans = dp(cur, idx + 1, obs);

        int left  = (cur - 1 + 1) % 3 + 1;
        int right = (cur - 1 + 2) % 3 + 1;
        
        if(obs[idx] != left) {
            ans = min(ans, dp(left, idx + 1, obs) + 1);
        }
        if(obs[idx] != right) {
            ans = min(ans, dp(right, idx + 1, obs) + 1);
        }
        return memo[cur][idx] = ans;
    }
    
    int minSideJumps(vector<int>& obs) {
        
        int n = obs.size();
        int cur = 2, idx = 0;
        
        memo.resize(4, vector<int>(n + 1, -1));
        
        return dp(cur, idx, obs);
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

