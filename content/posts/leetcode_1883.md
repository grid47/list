
+++
authors = ["Crafted by Me"]
title = "Leetcode 1883: Minimum Skips to Arrive at Meeting On Time"
date = "2019-09-07"
description = "In-depth solution and explanation for Leetcode 1883: Minimum Skips to Arrive at Meeting On Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1883.md" >}}
---
{{< youtube mKtvWPdnvzY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1884: Egg Drop With 2 Eggs and N Floors](https://grid47.xyz/posts/leetcode_1884) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

