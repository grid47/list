
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1621: Number of Sets of K Non-Overlapping Line Segments"
date = "2020-05-24"
description = "Solution to Leetcode 1621"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    int mod = (int) 1e9 + 7;
    int memo[1001][1001][2];
    int dp(int idx, int seg, bool startHere) {
        if(seg == 0) return 1;
        if(idx == n) return 0;

        if(memo[idx][seg][startHere] != -1) return memo[idx][seg][startHere];
        
        int ans = dp(idx + 1, seg, startHere); // will start on next or continue the seg
        if(startHere) {
            ans = (ans + dp(idx + 1, seg, false)) % mod; // stared new line            
        } else {
            ans = (ans + dp(idx, seg - 1, true)) % mod; // end the line here            
        }

        return memo[idx][seg][startHere] = ans;
    }

    int numberOfSets(int n, int k) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(0, k, true);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

