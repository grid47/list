
+++
authors = ["Crafted by Me"]
title = "Leetcode 1732: Find the Highest Altitude"
date = "2020-02-05"
description = "In-depth solution and explanation for Leetcode 1732: Find the Highest Altitude in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-highest-altitude/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int cur = 0;
        for(int x: gain) {
            cur += x;
            mx = max(mx, cur);
        }
        return mx;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #1733: Minimum Number of People to Teach](https://grid47.xyz/posts/leetcode_1733) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

