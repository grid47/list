
+++
authors = ["grid47"]
title = "Leetcode 3128: Right Triangles"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3128: Right Triangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Combinatorics","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SgwaC6fRCSE"
youtube_upload_date="2024-04-27"
youtube_thumbnail="https://i.ytimg.com/vi/SgwaC6fRCSE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/right-triangles/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> hr = grid;
        vector<vector<int>> vr = grid;        
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                hr[i][j] += hr[i][j - 1];
                // cout << hr[i][j] << " ";
            }
            // cout << "\n";
        }


        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vr[i][j] += vr[i - 1][j];            
                // cout << vr[i][j] << " ";
            }
            // cout << "\n";
        }


        long long  cnt = 0, net;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) {
                // if(i == 1 && j == 1) {
                //     cout << ((vr[m - 1][j] - vr[i][j]) + (i >= 1? vr[i - 1][j]: 0));                    
                // }

                net = (hr[i][n - 1] - 1) * ((vr[m - 1][j] - vr[i][j]) + (i > 0? vr[i - 1][j]: 0));
                // cout << i << " " << j << " " << net << "\n";
                cnt += net;
                
            }
        }        
        return cnt;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3128.md" >}}
---
{{< youtube SgwaC6fRCSE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3129: Find All Possible Stable Binary Arrays I](https://grid47.xyz/leetcode/solution-3129-find-all-possible-stable-binary-arrays-i/) |
| --- |
