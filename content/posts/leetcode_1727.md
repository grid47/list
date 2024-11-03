
+++
authors = ["Crafted by Me"]
title = "Leetcode 1727: Largest Submatrix With Rearrangements"
date = "2020-02-10"
description = "In-depth solution and explanation for Leetcode 1727: Largest Submatrix With Rearrangements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mtx) {
        int n = mtx[0].size(), m = mtx.size();
        vector<vector<int>> one(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if (mtx[j][i] == 1) { cnt++; } 
                else { cnt = 0; }
                one[j][i] = cnt;
            }
        }
        
        for(int i = 0; i < m; i++)
        sort(one[i].rbegin(), one[i].rend());

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                res = max(res, one[i][j] * (j + 1));
                
            }
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

