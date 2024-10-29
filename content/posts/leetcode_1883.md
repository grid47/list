
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1883: Minimum Skips to Arrive at Meeting On Time"
date = "2019-09-04"
description = "Solution to Leetcode 1883"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int s;
    vector<int> dist;
    vector<vector<int>> memo;
    
    int dp(int idx, int k) {
        if(idx < 0) return 0;
        
        if(memo[idx][k] != -1) return memo[idx][k];

        int res = (dp(idx - 1, k) + dist[idx] + s - 1) / s * s;
        
        if(k > 0) res = min(res, dp(idx - 1, k - 1) + dist[idx]);
        
        return memo[idx][k] = res;
    }

    int minSkips(vector<int>& A, int s, int target) {
        int n = A.size();
        this->s = s;
        this->dist = A;
        memo.resize(n + 1, vector<int>(n + 1, -1));
        
        for(int k = 0; k < n; k++) {
            if(dp(n - 1, k) <= (long long)s * target)
                return k;
        }

        return -1;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

