
+++
authors = ["Crafted by Me"]
title = "Leetcode 435: Non-overlapping Intervals"
date = "2023-08-25"
description = "In-depth solution and explanation for Leetcode 435: Non-overlapping Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/non-overlapping-intervals/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ivl) {
        sort(ivl.begin(), ivl.end());
        int ans = 0;
        int n = ivl.size();
        int prv = 0;
        for(int cur = 1; cur < n; cur++) {
            // [1, 5]. [3, 6]
            // [2, 8]. [3, 5]
            if(ivl[cur][0] < ivl[prv][1]) {
                ans++;
                if(ivl[cur][1] <= ivl[prv][1])
                    prv = cur;
            } else {
                prv = cur;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/435.md" >}}
---
{{< youtube mHsj83NoZDA >}}

| Next : [LeetCode #436: Find Right Interval](grid47.xyz/leetcode_436) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

