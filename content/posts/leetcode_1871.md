
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1871: Jump Game VII"
date = "2019-09-16"
description = "Solution to Leetcode 1871"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-vii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canReach(string s, int mnj, int mxj) {
        int n = s.length();
        vector<bool> dp(n, false);
        dp[0] = true;
        int pre = 0;
        for(int i = 0; i < n; i++) {
        
            if(i >= mnj && dp[i - mnj])
                pre++;

            if(i > mxj && dp[i - mxj -1])
                pre--;

            if (pre > 0) dp[i] = s[i] == '0';       
        }
        return dp[n - 1];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

