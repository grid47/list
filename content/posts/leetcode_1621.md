
+++
authors = ["grid47"]
title = "Leetcode 1621: Number of Sets of K Non-Overlapping Line Segments"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1621: Number of Sets of K Non-Overlapping Line Segments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    int mod = (int) 1e9 + 7;
    int memo[1001][1001][2];
    int dp(int idx, int seg, bool startHere) {
        if(seg == 0) return 1;
        if(idx == n) return 0;

        if(memo[idx][seg][startHere] != -1) return memo[idx][seg][startHere];
        
        int ans = dp(idx + 1, seg, startHere); // will start on next or continue the seg
        if(startHere) {
            ans = (ans + dp(idx + 1, seg, false)) % mod; // stared new line            
        } else {
            ans = (ans + dp(idx, seg - 1, true)) % mod; // end the line here            
        }

        return memo[idx][seg][startHere] = ans;
    }

    int numberOfSets(int n, int k) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(0, k, true);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1621.md" >}}
---
{{< youtube Zl-atHgL8QY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1624: Largest Substring Between Two Equal Characters](https://grid47.xyz/posts/leetcode_1624) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
