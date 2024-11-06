
+++
authors = ["Crafted by Me"]
title = "Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;
        int dp[1 << 17] = {1};
        dp[0] = 1;
        for(int a : nums) {
            for(int i = mx; i >= 0; i--) {
                dp[i | a] += dp[i];
            }
            mx |= a;
        }
        return dp[mx];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2044.md" >}}
---
{{< youtube _wBj3IMV7tY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2045: Second Minimum Time to Reach Destination](https://grid47.xyz/posts/leetcode_2045) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
