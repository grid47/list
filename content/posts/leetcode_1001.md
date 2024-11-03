
+++
authors = ["Crafted by Me"]
title = "Leetcode 1001: Grid Illumination"
date = "2022-02-05"
description = "In-depth solution and explanation for Leetcode 1001: Grid Illumination in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/grid-illumination/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        map<int, int> x, y, a_d, d_d;
        map<int, unordered_set<int>> set;
        for(int i = 0; i < lamps.size(); i++) {
            vector<int> axs = lamps[i];
            if(set[axs[0]].insert(axs[1]).second) {
                x[axs[0]]++;
                y[axs[1]]++;
                a_d[axs[0] + axs[1]]++;
                d_d[axs[0] - axs[1]]++;
            }
        }

        int sz = queries.size();
        vector<int> res;

        for(int k = 0; k < sz; k++) {
            vector<int> q = queries[k];
            int i = q[0], j = q[1];
            
            if(x[i] || y[j] || a_d[i + j] || d_d[i - j]) {
                res.push_back(1);
                for(int li = i - 1; li <= i + 1; li++)
                for(int lj = j - 1; lj <= j + 1; lj++){
                    if(set[li].erase(lj)) {
                        x[li]--;
                        y[lj]--;
                        a_d[li + lj]--;
                        d_d[li - lj]--;
                    }
                }
            } else res.push_back(0);
        }

        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1001.md" >}}
---
{{< youtube Mjbq8aGPBr8 >}}

| Next : [LeetCode #1002: Find Common Characters](grid47.xyz/leetcode_1002) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

