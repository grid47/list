
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1931: Painting a Grid With Three Different Colors"
date = "2019-07-18"
description = "Solution to Leetcode 1931"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int memo[1001][1024] = {};
    int mod = (int) 1e9 + 7;
    int colorTheGrid(int m, int n, int i = 0, int j = 0, int cur = 0, int prv = 0) {
        if(i == m) return colorTheGrid(m, n, 0, j + 1, 0, cur);
                
        if(j == n) return 1;
        
        if(i == 0 && memo[j][prv]) return memo[j][prv];        
        
        int up = i == 0? 0: (cur >> (i - 1) * 2) & 3;
        int lft = (prv >> (i) * 2) & 3;
        
        int ans = 0;
        for(int k = 1; k < 4; k++) {
            if(up != k && lft != k)
                ans = (ans + colorTheGrid(m, n, i + 1, j, cur + (k << i * 2), prv)) % mod;
        }
        if(i == 0) memo[j][prv] = ans;
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

