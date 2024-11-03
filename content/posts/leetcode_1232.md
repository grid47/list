
+++
authors = ["Crafted by Me"]
title = "Leetcode 1232: Check If It Is a Straight Line"
date = "2021-06-19"
description = "In-depth solution and explanation for Leetcode 1232: Check If It Is a Straight Line in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-it-is-a-straight-line/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cord) {
        double slopt = (cord[1][0] - cord[0][0]) == 0? INT_MAX: (double)(cord[1][1] - cord[0][1]) / (double)(cord[1][0] - cord[0][0]);
        for(int i = 2; i < cord.size(); i++) {
            double slp = (cord[i][0] - cord[0][0]) == 0?INT_MAX: (double)(cord[i][1] - cord[0][1]) / (double)(cord[i][0] - cord[0][0]);
            if(slp != slopt) return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1232.md" >}}
---
{{< youtube _tfiTQNZCbs >}}

| Next : [LeetCode #1233: Remove Sub-Folders from the Filesystem](grid47.xyz/leetcode_1233) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

