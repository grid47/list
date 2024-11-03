
+++
authors = ["Crafted by Me"]
title = "Leetcode 978: Longest Turbulent Subarray"
date = "2022-02-28"
description = "In-depth solution and explanation for Leetcode 978: Longest Turbulent Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-turbulent-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        vector<int> dp(2, 1);
        
        int res = 1, n = arr.size(), prv = 0;

        for(int i = 1; i < n; i++) {

            if ((prv == 0 || prv == -1) && arr[i - 1] < arr[i] ) {
                dp[0] = dp[1] + 1;
                res = max(res, dp[0]);
                prv = 1;
            } else if ((prv == 0 || prv == 1) && arr[i - 1] > arr[i] ) {
                dp[1] = dp[0] + 1;
                res = max(res, dp[1]);
                prv = -1;
            }
            else if (arr[i - 1] == arr[i] ) {
                dp[0] = 1;
                dp[1] = 1;
                prv = 0;
            } else {
                dp[0] = 2;
                dp[1] = 2;
                prv = (arr[i - 1] < arr[i]) ? 1 : -1;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/978.md" >}}
---

| Next : [LeetCode #979: Distribute Coins in Binary Tree](https://grid47.xyz/posts/leetcode_979) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

