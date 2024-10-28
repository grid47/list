
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2596: Check Knight Tour Configuration"
date = "2017-09-20"
description = "Solution to Leetcode 2596"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-knight-tour-configuration/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        map<int, pair<int, int>> mp;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[grid[i][j]] = {i, j};
            }
        }
        if(mp[0] != make_pair(0,0)) return false;
        int p = 0, q = 0;
        for(int i = 1; i < n * n; i++) {
            auto it = mp[i];
            int x = it.first;
            int y = it.second;
            if((abs(x - p) == 1 && abs(y - q) == 2) ||
               (abs(x - p) == 2 && abs(y - q) == 1)) {
                p = x;
                q = y;
            } else return false;
        }
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

