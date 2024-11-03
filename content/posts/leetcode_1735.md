
+++
authors = ["Crafted by Me"]
title = "Leetcode 1735: Count Ways to Make Array With Product"
date = "2020-02-02"
description = "In-depth solution and explanation for Leetcode 1735: Count Ways to Make Array With Product in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---


| Next : [LeetCode #1736: Latest Time by Replacing Hidden Digits](grid47.xyz/leetcode_1736) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

