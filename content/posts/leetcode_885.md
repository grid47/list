
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 885: Spiral Matrix III"
date = "2022-05-30"
description = "Solution to Leetcode 885"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res = {{rStart, cStart}};
        int dx = 0, dy = 1, tmp;
        for(int n = 0; res.size() < rows* cols; n++) {
            for(int i = 0; i < n / 2 + 1; i++) {
                rStart += dx, cStart += dy;
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    res.push_back({rStart, cStart});
                
            }
            tmp = dx, dx = dy, dy = -tmp;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/885.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

