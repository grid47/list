
+++
authors = ["grid47"]
title = "Leetcode 3044: Most Frequent Prime"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3044: Most Frequent Prime in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Matrix","Counting","Enumeration","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-prime/description/)

---
**Code:**

{{< highlight cpp >}}
char sieve[1000001] = {};
class Solution {
public:
    int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};
    void make() {
        sieve[1] = 1;
        for (int i = 2; i < 1000001; i++) {
            if (!sieve[i]) for (int j = 2*i; j < 1000001; j += i) sieve[j] = 1;
        }
    } 
    int mostFrequentPrime(vector<vector<int>>& mat) {
        if (sieve[1] == 0) make();
        map<int, int> freq;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                for (int k = 0; k < 8; k++) {
                    int a = i, b = j;
                    int cur = 0;
                    while (a >= 0 && b >= 0 && a < mat.size() && b < mat[i].size()) {
                        cur *= 10;
                        cur += mat[a][b];
                        if(cur>10 && sieve[cur] == 0) freq[cur]++;
                        a += dx[k]; b += dy[k];
                    }
                }
            }
        }
        int mx = -1;
        int ans = -1;
        for (auto i : freq) {
            if(i.second >= mx) {
                ans = i.first;
                mx = i.second;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3044.md" >}}
---
{{< youtube vyLo_FMR3IU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3045: Count Prefix and Suffix Pairs II](https://grid47.xyz/posts/leetcode-3044-most-frequent-prime-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
