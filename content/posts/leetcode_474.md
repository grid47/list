
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 474: Ones and Zeroes"
date = "2023-07-13"
description = "Solution to Leetcode 474"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ones-and-zeroes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMaxForm(vector<string>& strs, int zeros, int ones) {
        int i, j, p = strs.size();
        vector<vector<int>> dp(zeros + 1, vector<int>(ones+1));

        for(auto &s : strs) {
            int currOne = count(s.begin(), s.end(), '1');
            int currZero = s.size() - currOne;
            for(int j = ones ; j >= currOne; j--) 
            for(int i = zeros; i >= currZero; i--) {
               dp[i][j] = max(dp[i][j], 1 + dp[i- currZero ][j-currOne]);
            }
        }

        return dp[zeros][ones];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

