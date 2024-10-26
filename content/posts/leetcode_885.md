
+++
authors = ["Yasir"]
title = "Leetcode 885: Spiral Matrix III"
date = "2022-05-26"
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

{{< highlight html >}}
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

