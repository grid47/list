
+++
authors = ["Yasir"]
title = "Leetcode 837: New 21 Game"
date = "2022-07-14"
description = "Solution to Leetcode 837"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/new-21-game/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    double new21Game(int n, int k, int w) {
        

        if(k == 0 || n >= k + w)
            return 1;

        
        /*
        
        You will get number x (1 to w) in a draw, with probablity 1 / w
        
        if you need probablity of getting i points in a draw
        
        we can do slecting (i - x) points with probablity dp[i - x] and
        selecting x with probablity x
        
        so doing it together dp[i - x] * 1 / w
        
        and this to every x in [1, w] to get net prob of dp[i].
        
        once the pionts has crossed a limit k, there will be no more selections.
        
        then we look for only the over flows from previous trials.

        why target probablity counted from k onward instead of dp[n].

        */        
        
        vector<double> dp(n+1);
        dp[0] = 1;
        double Wsum = 1.0, res = 0.0;
        for(int i = 1; i <= n; i++) {
            dp[i] = Wsum/ w;
            if(i < k) Wsum += dp[i];
            else res += dp[i];
            if(i - w >= 0) Wsum -= dp[i - w];
        }
        return res;
    }
};
{{< /highlight >}}

