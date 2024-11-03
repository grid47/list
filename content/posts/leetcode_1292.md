
+++
authors = ["Crafted by Me"]
title = "Leetcode 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold"
date = "2021-04-20"
description = "In-depth solution and explanation for Leetcode 1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int hit) {
        int m = mat.size(), n = mat[0].size();
        int res = 0, len = 1;
        vector<vector<int>> sum(m + 1, vector<int> (n + 1));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
                if(i >= len && j >= len && sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len] <= hit)
                    res = len++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1292.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

