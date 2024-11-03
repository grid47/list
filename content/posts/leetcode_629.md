
+++
authors = ["Crafted by Me"]
title = "Leetcode 629: K Inverse Pairs Array"
date = "2023-02-12"
description = "In-depth solution and explanation for Leetcode 629: K Inverse Pairs Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-inverse-pairs-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int dp[1001][1001] = {};
int kInversePairs(int n, int k) {
    if (k <= 0)
        return k == 0;
    if (dp[n][k] == 0) {
        dp[n][k] = 1;
        for (auto i = 0; i < n; ++i) {
            dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % 1000000007;
        }
    }
    return dp[n][k] - 1;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/629.md" >}}
---


"| 630: Course Schedule III |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

