
+++
authors = ["Crafted by Me"]
title = "Leetcode 3044: Most Frequent Prime"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 3044: Most Frequent Prime in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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


---
{{< youtube vyLo_FMR3IU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3045: Count Prefix and Suffix Pairs II](https://grid47.xyz/posts/leetcode_3045) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

