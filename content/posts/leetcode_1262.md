
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1262: Greatest Sum Divisible by Three"
date = "2021-05-17"
description = "Solution to Leetcode 1262"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/greatest-sum-divisible-by-three/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(3, 0);

        for(int a : nums)
        for(int i : vector<int>(dp))
        dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);

        return dp[0];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

