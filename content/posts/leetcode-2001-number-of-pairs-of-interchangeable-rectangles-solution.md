
+++
authors = ["grid47"]
title = "Leetcode 2001: Number of Pairs of Interchangeable Rectangles"
date = "2024-04-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2001: Number of Pairs of Interchangeable Rectangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long cnt = 0;
        for(auto r: rectangles) {
            double x = (double)r[0]/ r[1];
            if(mp.find(x) != mp.end()) cnt += mp[x];
            mp[x]++;
        }

        // int cnt = 0;
        // for(auto &it: mp) 
        // {
            // cout << it.second << ' ';
            // cnt = cnt + it.second * (it.second -1 ) / 2;
        // }

        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2001.md" >}}
---
{{< youtube lEQ8ZlLOuyQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2002: Maximum Product of the Length of Two Palindromic Subsequences](https://grid47.xyz/posts/leetcode-2002-maximum-product-of-the-length-of-two-palindromic-subsequences-solution/) |
| --- |
