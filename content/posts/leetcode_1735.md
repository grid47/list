
+++
authors = ["Yasir"]
title = "Leetcode 1735: Count Ways to Make Array With Product"
date = "2020-01-29"
description = "Solution to Leetcode 1735"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-ways-to-make-array-with-product/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    vector<int> sieve(int num) {
        vector<bool> tes(num + 1, true);
        tes[0] = false;
        tes[1] = false;
        for(int i = 2; i < num/2 + 1; i++) {
            if(tes[i]) {
                for(int j = i * i; j <= num; j += i)
                    tes[j] = false;
            }
        }
        vector<int> ans;
        for(int i = 0; i <= num; i++)
            if(tes[i]) ans.push_back(i);
        return ans;
    }
    
    int mod = (int) 1e9 + 7;
    
    vector<int> waysToFillArray(vector<vector<int>>& q) {

        vector<int> primes = sieve(100);
        cout << primes.size();
        
        vector<vector<int>> comb(10013, vector<int>(14, 0));
        comb[0][0] = 1;
        for(int i = 1; i < 10013; i++)
          for(int j = 0; j < 14; j++)
        comb[i][j] = j == 0? 1: ( comb[i - 1][j - 1] + comb[i - 1][j] ) % mod;

        vector<int> ans(q.size(), 1);

        for(int i = 0; i < q.size(); i++) {
            int n = q[i][0], k = q[i][1];
            for(int x : primes) {
                int cnt = 0;
                while(k % x == 0) {
                    k = k / x;
                    cnt++;
                }
                ans[i] = (long) ans[i] * comb[n - 1 + cnt][cnt] % mod;
            }
            if(k != 1) ans[i] = (long) ans[i] * n % mod;
        }        
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

