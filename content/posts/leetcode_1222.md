
+++
authors = ["Yasir"]
title = "Leetcode 1222: Queens That Can Attack the King"
date = "2021-06-25"
description = "Solution to Leetcode 1222"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

