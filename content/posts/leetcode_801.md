
+++
authors = ["Crafted by Me"]
title = "Leetcode 801: Minimum Swaps To Make Sequences Increasing"
date = "2022-08-24"
description = "In-depth solution and explanation for Leetcode 801: Minimum Swaps To Make Sequences Increasing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int minSwap(vector<int>& n1, vector<int>& n2) {
        int n = n1.size();
        vector<vector<int>> res(n, vector<int>(2, 0));
        res[0][0] = 0;
        res[0][1] = 1;
        for(int i = 1; i < n; i++) {
            bool bothInc    = n1[i - 1] < n1[i] && n2[i - 1] < n2[i];
            bool crossInc   = n1[i - 1] < n2[i] && n2[i - 1] < n1[i];
            
            if(bothInc && crossInc) {
                res[i][0] = min(res[i - 1][0], res[i - 1][1]);
                res[i][1] = min(res[i - 1][0], res[i - 1][1]) + 1;                
            } else if(bothInc) {
                res[i][0] = res[i - 1][0];
                res[i][1] = res[i - 1][1] + 1;                                
            } else {
                res[i][0] = res[i - 1][1];
                res[i][1] = res[i - 1][0] + 1;                                                
            }
        }
        return min(res[n - 1][0], res[n - 1][1]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/801.md" >}}
---

| Next : [LeetCode #802: Find Eventual Safe States](https://grid47.xyz/posts/leetcode_802) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

