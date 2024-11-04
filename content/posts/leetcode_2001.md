
+++
authors = ["Crafted by Me"]
title = "Leetcode 2001: Number of Pairs of Interchangeable Rectangles"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2001: Number of Pairs of Interchangeable Rectangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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


---
{{< youtube lEQ8ZlLOuyQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2002: Maximum Product of the Length of Two Palindromic Subsequences](https://grid47.xyz/posts/leetcode_2002) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

