
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 891: Sum of Subsequence Widths"
date = "2022-05-24"
description = "Solution to Leetcode 891"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-subsequence-widths/description/)

---
{{< youtube nan >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

