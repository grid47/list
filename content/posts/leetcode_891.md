
+++
authors = ["Crafted by Me"]
title = "Leetcode 891: Sum of Subsequence Widths"
date = "2022-05-26"
description = "In-depth solution and explanation for Leetcode 891: Sum of Subsequence Widths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-subsequence-widths/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        
        typedef long long ll;
        
        ll mod = 1e9 + 7;
        int n = nums.size();
        ll res = 0;
        sort(nums.begin(), nums.end());
        ll c = 1;
        for(int i = 0; i < n; i++, c = (c * 2)% mod)
        res = ((ll) nums[i] * c - (ll) nums[n - 1 - i] * c + res) % mod;

        return (int) res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/891.md" >}}
---

| Next : [LeetCode #892: Surface Area of 3D Shapes](https://grid47.xyz/posts/leetcode_892) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

