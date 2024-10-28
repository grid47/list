
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 935: Knight Dialer"
date = "2022-04-08"
description = "Solution to Leetcode 935"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/knight-dialer/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1e9 + 7;
public:
    int knightDialer(int n) {
        long long res = 0;
        vector<vector<long long>> arr(4, vector<long long>(3, -1));
        vector<vector<vector<long long>>> mem(n + 1, arr);

        for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
        {
            res = (res + path(i, j, n, mem))% mod;
        }
        return res;
    }

long long path(int i, int j, int n, vector<vector<vector<long long>>> &mem) {
        
        if(i < 0 || j < 0|| i >= 4 || j >= 3 || (i==3 && j !=1))
            return 0;

        if(mem[n][i][j] != -1) return mem[n][i][j] % mod;

        if (n == 1) return 1;

        mem[n][i][j] = path(i -1 , j -2, n - 1, mem) % mod +
                  path(i -1 , j +2, n - 1, mem) % mod +
                  path(i -2 , j -1, n - 1, mem) % mod +
                  path(i -2 , j +1, n - 1, mem) % mod +
                  path(i +1 , j -2, n - 1, mem) % mod +
                  path(i +1 , j +2, n - 1, mem) % mod +
                  path(i +2 , j -1, n - 1, mem) % mod +
                  path(i +2 , j +1, n - 1, mem) % mod;
        return mem[n][i][j];
    }

};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

