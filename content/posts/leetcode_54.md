
+++
authors = ["Crafted by Me"]
title = "Leetcode 54: Spiral Matrix"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 54: Spiral Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mtx) {
        int cBgn = 0, cEnd = mtx[0].size()  - 1;
        int rBgn = 0, rEnd = mtx.size() - 1;
        vector<int> ans;
        while(cBgn <= cEnd && rBgn <= rEnd) {
            for(int i = cBgn; i <= cEnd; i++)
                ans.push_back(mtx[rBgn][i]);
            rBgn++;
            for(int i = rBgn; i <= rEnd; i++)
                ans.push_back(mtx[i][cEnd]);
            cEnd--;
            if(rBgn <= rEnd)
            for(int i = cEnd; i >= cBgn; i--)
                ans.push_back(mtx[rEnd][i]);
            rEnd--;
            if(cBgn <= cEnd)            
            for(int i = rEnd; i >= rBgn; i--)
                ans.push_back(mtx[i][cBgn]);
            cBgn++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/54.md" >}}
---
{{< youtube fcn8qkRcFVM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #55: Jump Game](https://grid47.xyz/posts/leetcode_55) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

