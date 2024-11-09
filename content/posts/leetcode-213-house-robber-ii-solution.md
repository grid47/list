
+++
authors = ["grid47"]
title = "Leetcode 213: House Robber II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 213: House Robber II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/house-robber-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            
        int r1 = dp[n - 1];
        
        dp.resize(n + 1, 0);
        dp[1] = 0;
        dp[2] = nums[1];        
        for(int i = 3; i < n + 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);        
        
        return max(dp[n], r1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/213.md" >}}
---
{{< youtube rWAJCfYYOvM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #215: Kth Largest Element in an Array](https://grid47.xyz/posts/leetcode-213-house-robber-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
