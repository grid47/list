
+++
authors = ["grid47"]
title = "Leetcode 1727: Largest Submatrix With Rearrangements"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1727: Largest Submatrix With Rearrangements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NYyIVuSCfOA"
youtube_upload_date="2023-11-26"
youtube_thumbnail="https://i.ytimg.com/vi/NYyIVuSCfOA/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1727.md" >}}
---
{{< youtube NYyIVuSCfOA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1732: Find the Highest Altitude](https://grid47.xyz/leetcode/solution-1732-find-the-highest-altitude/) |
| --- |