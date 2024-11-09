
+++
authors = ["grid47"]
title = "Leetcode 1824: Minimum Sideway Jumps"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1824: Minimum Sideway Jumps in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sideway-jumps/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1824.md" >}}
---
{{< youtube IDTzmXD5H58 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1827: Minimum Operations to Make the Array Increasing](https://grid47.xyz/posts/leetcode-1824-minimum-sideway-jumps-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
