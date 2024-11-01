
+++
authors = ["Crafted by Me"]
title = "Leetcode 646: Maximum Length of Pair Chain"
date = "2023-01-26"
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

{{< highlight cpp >}}

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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/646.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

