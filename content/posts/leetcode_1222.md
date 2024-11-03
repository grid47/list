
+++
authors = ["Crafted by Me"]
title = "Leetcode 1222: Queens That Can Attack the King"
date = "2021-06-29"
description = "In-depth solution and explanation for Leetcode 1222: Queens That Can Attack the King in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/queens-that-can-attack-the-king/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
        vector<vector<bool>> b(8, vector<bool>(8, false));
        for(auto q: queens)
        b[q[0]][q[1]] = true;

        vector<vector<int>> res;
        for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            if ( i == 0 && j == 0) continue;
            int x = k[0] + i, y = k[1] + j;
            while(min(x, y) >= 0 && max(x, y) < 8) {
                if(b[x][y]) {
                        res.push_back({x, y});
                        break;
                }
                x += i;
                y += j;
            }
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1222.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

