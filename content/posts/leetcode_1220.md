
+++
authors = ["grid47"]
title = "Leetcode 1220: Count Vowels Permutation"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1220: Count Vowels Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-vowels-permutation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n, mod = (int) 1e9 + 7;
    vector<vector<int>> mem;
    int dp(int prv, int cur) {
        if(cur == n) return 1;
        if(mem[prv][cur] != -1) return mem[prv][cur];
        long ans = 0;
        switch(prv) {
            case 0:
                ans = (ans + dp(1, cur + 1)) % mod;
                ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                ans = (ans + dp(4, cur + 1)) % mod;
                ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 1:
        /*  a -> xeixu  e -> axixx  i -> xexox  o -> xxixx  u -> xxiox  */            
                // ans = (ans + dp(1, cur + 1)) % mod;
                ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                // ans = (ans + dp(4, cur + 1)) % mod;
                ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 2:
                ans = (ans + dp(1, cur + 1)) % mod;
                // ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                // ans = (ans + dp(4, cur + 1)) % mod;
                // ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 3:
                // ans = (ans + dp(1, cur + 1)) % mod;
                ans = (ans + dp(2, cur + 1)) % mod;
                // ans = (ans + dp(3, cur + 1)) % mod;
                ans = (ans + dp(4, cur + 1)) % mod;
                // ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 4:
                // ans = (ans + dp(1, cur + 1)) % mod;
                // ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                // ans = (ans + dp(4, cur + 1)) % mod;
                // ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 5:
                // ans = (ans + dp(1, cur + 1)) % mod;
                // ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                ans = (ans + dp(4, cur + 1)) % mod;
                // ans = (ans + dp(5, cur + 1)) % mod;
            break;                                                                        
        }

        return mem[prv][cur] = ans;
    }

    int countVowelPermutation(int n) {
        this->n = n;
        mem.resize(8, vector<int>(n + 1, -1));
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1220.md" >}}
---
{{< youtube VUVpTZVa7Ls >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1222: Queens That Can Attack the King](https://grid47.xyz/posts/leetcode_1222) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
