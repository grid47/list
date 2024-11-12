
+++
authors = ["grid47"]
title = "Leetcode 1573: Number of Ways to Split a String"
date = "2024-06-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1573: Number of Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-split-a-string/description/)

---
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1573.md" >}}
---
{{< youtube DVcHb_poT6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers](https://grid47.xyz/posts/leetcode-1577-number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers-solution/) |
| --- |
