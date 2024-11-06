
+++
authors = ["Crafted by Me"]
title = "Leetcode 2312: Selling Pieces of Wood"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2312: Selling Pieces of Wood in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Memoization"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/selling-pieces-of-wood/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> v, h;
    vector<vector<int>> p;
    vector<vector<long long>> mem, mp;
    
    long long dp(int m, int n) {
        if(m <= 0 || n <= 0) return 0;

        if(mem[m][n] != -1) return mem[m][n];
        
        long long ans = mp[m][n];

        for(int i = 1; i <= m / 2; i++) {
            ans = max(ans, dp(m - i, n) + dp(i, n));
        }
        for(int i = 1; i <= n / 2; i++) {
            ans = max(ans, dp(m, n - i) + dp(m, i));
        }
        
        return mem[m][n] = ans;
    }
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        p = prices;
        mem.resize(m + 1, vector<long long>(n + 1, -1));
        mp.resize(m + 1, vector<long long>(n + 1, 0));        

        for(int i = 0; i < p.size(); i++) {
            mp[p[i][0]][p[i][1]] = p[i][2];
            // v.push_back(p[i][0]);
            // h.push_back(p[i][1]);
        }

        // sort(v.begin(), v.end());
        // sort(h.begin(), h.end());        

        return dp(m, n);
        /*
        cut
        continue
        m, n == 200
        on cut record the rest
        check rest on mem, if yes directly add res
        */        
    }
};
{{< /highlight >}}


---
{{< youtube Zho0AXQr58s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2313: Minimum Flips in Binary Tree to Get Result](https://grid47.xyz/posts/leetcode_2313) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
