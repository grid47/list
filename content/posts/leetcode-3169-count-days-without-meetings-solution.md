
+++
authors = ["grid47"]
title = "Leetcode 3169: Count Days Without Meetings"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3169: Count Days Without Meetings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-days-without-meetings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& mt) {
        int net = days;
        int n = mt.size();
        sort(mt.begin(), mt.end());
        vector<int> tuned;
        vector<int> pt = mt[0];
        if(n == 1) return net - (pt[1] - pt[0] + 1);
        for(int i = 1; i < n; i++) {
            if (mt[i][0] <= pt[1])
                pt[1] = max(pt[1], mt[i][1]);
            else {
                net -= pt[1] - pt[0] + 1;
                pt = mt[i];
            }
            if(i + 1 == n) net -= pt[1] - pt[0] + 1;
        }
        return net;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3169.md" >}}
---
{{< youtube 72-mDiuXbLk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #3178: Find the Child Who Has the Ball After K Seconds](https://grid47.xyz/posts/leetcode-3178-find-the-child-who-has-the-ball-after-k-seconds-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
