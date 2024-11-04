
+++
authors = ["Crafted by Me"]
title = "Leetcode 1335: Minimum Difficulty of a Job Schedule"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1335: Minimum Difficulty of a Job Schedule in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> job;
    int memo[301][11];
    int dp(int idx, int d) {

        if(idx == job.size() && d == 0) return 0;
        if(idx == job.size() || d == 0) return INT_MAX;        

        if(memo[idx][d] != -1) return memo[idx][d];

        int mx = job[idx], ans = INT_MAX;

        for(int i = idx; i < job.size(); i++) {
            mx = max(mx, job[i]);
            int ret = dp(i + 1, d - 1);
            if(ret != INT_MAX)
            ans = min(ans, mx + ret);
        }

        return memo[idx][d] = ans;
    }
    
    int minDifficulty(vector<int>& job, int d) {
        if(job.size() < d) return -1;
        
        this->job = job;
        memset(memo, -1, sizeof(memo));
        return dp(0, d);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1335.md" >}}
---
{{< youtube h48x-eQaqk4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1336: Number of Transactions per Visit](https://grid47.xyz/posts/leetcode_1336) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

