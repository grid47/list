
+++
authors = ["Crafted by Me"]
title = "Leetcode 1014: Best Sightseeing Pair"
date = "2022-01-23"
description = "In-depth solution and explanation for Leetcode 1014: Best Sightseeing Pair in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-sightseeing-pair/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {

        int res = 0, cur = 0;

        for(int x : val) {
            res = max(res, cur + x);
            cur = max(cur, x) - 1;
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1014.md" >}}
---


| Next : [LeetCode #1015: Smallest Integer Divisible by K](grid47.xyz/leetcode_1015) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

