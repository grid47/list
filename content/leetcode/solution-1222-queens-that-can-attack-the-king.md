
+++
authors = ["grid47"]
title = "Leetcode 1222: Queens That Can Attack the King"
date = "2024-07-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1222: Queens That Can Attack the King in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1226: The Dining Philosophers](https://grid47.xyz/leetcode/solution-1226-the-dining-philosophers/) |
| --- |