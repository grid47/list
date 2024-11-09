
+++
authors = ["grid47"]
title = "Leetcode 486: Predict the Winner"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 486: Predict the Winner in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Recursion","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/predict-the-winner/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<int> nums;
    vector<vector<map<int, int>>> memo;
    
    int dp(int l, int r, int net) {
        
        if(l == r) return nums[l];
        
        if(memo[l][r].count(net)) return memo[l][r][net];
        
        int ans = net - dp(l + 1, r, net - nums[l]);
        ans = max(ans, net - dp(l, r - 1, net - nums[r]));
        
        return memo[l][r][net] = ans;
    }
    
    bool predictTheWinner(vector<int>& nums) {

        this->nums = nums;
        int n = nums.size();
        memo.resize(n + 1, vector<map<int,int>>(n + 1));
        
        int net = accumulate(nums.begin(), nums.end(), 0);
        
        int ret = dp(0, n - 1, net);

        return ret >= net - ret;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/486.md" >}}
---
{{< youtube KjlXtj7IwyY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #494: Target Sum](https://grid47.xyz/posts/leetcode-494-target-sum-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
