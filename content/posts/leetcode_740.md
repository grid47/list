
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 740: Delete and Earn"
date = "2022-10-20"
description = "Solution to Leetcode 740"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-and-earn/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> val(n + 1, 0);
        vector<int> dp (n + 1, 0);
        
        for(int num : nums)
          val[num] += num;
        
        dp[0] = 0;
        dp[1] = val[0];
        for(int i = 1; i < n; i++)
        dp[i + 1] = max(dp[i], dp[i - 1] + val[i]);
        
        return dp[n];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

