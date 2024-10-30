
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1573: Number of Ways to Split a String"
date = "2020-07-11"
description = "Solution to Leetcode 1573"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-split-a-string/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numWays(string s) {
        
        long n = s.size();
        int one = 0;
        for(char x: s)
            one += (x == '0')? 0: 1;
        
        int mod = (int) 1e9 + 7;
        
        if(one == 0) return (int)((n - 2) * (n - 1) / 2 % mod);
        
            
        if(one % 3 != 0) return 0;
        
        long long waysOfFirstCut = 0, waysOfSecondCut = 0;
        int net = one / 3, tmp = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') tmp++;
            if(tmp == net) waysOfFirstCut++;
            else if(tmp == 2 * net) waysOfSecondCut++;
        }
        
        return (int)(waysOfFirstCut *waysOfSecondCut % mod) ;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

