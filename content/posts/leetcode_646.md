
+++
authors = ["Yasir"]
title = "Leetcode 646: Maximum Length of Pair Chain"
date = "2023-01-20"
description = "Solution to Leetcode 646"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-pair-chain/description/)

---

**Code:**

{{< highlight html >}}

class Solution {
public:

    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        
        int n = pairs.size();
        
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    mx = max(mx, dp[i]);
                }
            }
        }
        
        return mx;
    }
};
{{< /highlight >}}

