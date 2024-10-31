
+++
authors = ["Crafted by Me"]
title = "Leetcode 1674: Minimum Moves to Make Array Complementary"
date = "2020-04-02"
description = "Solution to Leetcode 1674"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMoves(vector<int>& num, int lmt) {
        int n = num.size();
        vector<int> dp(2*lmt +2,0);
        for(int i = 0; i < n/2; i++) {
            int a = num[i];
            int b = num[n-1-i];
            dp[2] += 2;
            dp[min(a,b)+1] -= 1;
            dp[a+b] -= 1;
            dp[a+b+1] += 1;
            dp[max(a,b) + lmt +1] += 1;
            
            }
        //for(int i = 1; i < n; i++)
           // dp[i] += dp[i - 1];
        
        int cur = 0, res = 2* n;
        for(int i = 2; i < 2 * lmt + 1; i++) {
            cur += dp[i];
            res = min(res, cur);
            }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

