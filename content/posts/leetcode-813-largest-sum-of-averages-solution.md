
+++
authors = ["grid47"]
title = "Leetcode 813: Largest Sum of Averages"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 813: Largest Sum of Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-sum-of-averages/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double memo[200][200];
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(memo, 0, sizeof(memo));
        int n = nums.size();
        double cur = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            memo[i + 1][1] = cur / (i+ 1);
        }
        return search(n, k, nums);
    }

    double search(int n, int k, vector<int> &nums) {
        if(memo[n][k] > 0) return memo[n][k];
        double cur = 0;
        for(int i = n - 1; i > 0; i--) {
            cur += nums[i];
            memo[n][k] = max(memo[n][k], search(i, k - 1, nums) + cur / (n - i));
        }
        return memo[n][k];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/813.md" >}}
---
{{< youtube 3eqwUW6_cx4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #814: Binary Tree Pruning](https://grid47.xyz/posts/leetcode-814-binary-tree-pruning-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}