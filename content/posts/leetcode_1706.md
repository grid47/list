
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1706: Where Will the Ball Fall"
date = "2020-02-29"
description = "Solution to Leetcode 1706"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/where-will-the-ball-fall/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < n; i++) {
            int i1 = i, i2;
            for(int j = 0; j < m; j++) {
                i2 = i1 + grid[j][i1];
                if(i2 <0 || i2 >= n || grid[j][i1] != grid[j][i2]) {
                    i1 = -1;
                    break;
                }
                i1 = i2;
            }
            res.push_back(i1);
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

