
+++
authors = ["Yasir"]
title = "Leetcode 2312: Selling Pieces of Wood"
date = "2018-07-01"
description = "Solution to Leetcode 2312"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/selling-pieces-of-wood/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

