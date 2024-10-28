
+++
authors = ["Yasir"]
title = "Leetcode 891: Sum of Subsequence Widths"
date = "2022-05-22"
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

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

