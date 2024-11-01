
+++
authors = ["Crafted by Me"]
title = "Leetcode 474: Ones and Zeroes"
date = "2023-07-17"
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/474.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

