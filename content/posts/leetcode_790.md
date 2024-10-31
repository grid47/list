
+++
authors = ["Crafted by Me"]
title = "Leetcode 790: Domino and Tromino Tiling"
date = "2022-09-03"
description = "Solution to Leetcode 790"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/domino-and-tromino-tiling/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        vector<long long> v(10001, 0);
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        if(n <= 3) return v[n];
        for(int i = 4; i <= n; i++) {
            v[i]  = (2 * v[i-1] + v[i-3]);
            v[i] %= mod;
        }
        return v[n];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/790.md" >}}

---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

