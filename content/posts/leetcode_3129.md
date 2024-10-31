
+++
authors = ["Crafted by Me"]
title = "Leetcode 3129: Find All Possible Stable Binary Arrays I"
date = "2016-04-08"
description = "Solution to Leetcode 3129"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<vector<vector<int>>>> mem;
    int limit, mod = 1000000007;
    int dp(int z, int o, int p, int lmt, vector<vector<vector<vector<int>>>> &mem) {
        if(z == 0 && o == 0) return 1;
        if(mem[p][o][lmt][z] != -1) return mem[p][o][lmt][z];
        long ans = 0;
        if(p == 0) {
            if(z > 0 && lmt < limit)    ans += dp(z - 1, o, 0, lmt + 1, mem) % mod;
            if(o > 0)                   ans += dp(z, o - 1, 1, 1, mem)% mod;
        } else {
            if(o > 0 && lmt < limit)    ans += dp(z, o - 1, 1, lmt + 1, mem)% mod;
            if(z > 0)                   ans += dp(z - 1, o, 0, 1, mem)% mod;
        }
        return mem[p][o][lmt][z] = ans % mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<vector<int>>>> mem(2, vector<vector<vector<int>>>(one + 1, vector<vector<int>>(limit + 1, vector<int>(zero + 1, -1))));
        this->limit = limit;
        long res  = (dp(zero - 1, one, 0, 1, mem) +
                     dp(zero, one - 1, 1, 1, mem)) % mod;
        return res;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

