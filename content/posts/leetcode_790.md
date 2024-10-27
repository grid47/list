
+++
authors = ["Yasir"]
title = "Leetcode 790: Domino and Tromino Tiling"
date = "2022-08-30"
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

{{< highlight html >}}
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

