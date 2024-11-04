
+++
authors = ["Crafted by Me"]
title = "Leetcode 3101: Count Alternating Subarrays"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 3101: Count Alternating Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-alternating-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        dp[0] = 1;
        long long res = 1;
        for(int i = 1; i < n; i++) {
            dp[i] = nums[i] == nums[i - 1]? 1: dp[i - 1] + 1;
            // cout << dp[i];
            res += dp[i];
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube EZSNwFnWaV8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3102: Minimize Manhattan Distances](https://grid47.xyz/posts/leetcode_3102) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

