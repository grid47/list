
+++
authors = ["grid47"]
title = "Leetcode 2596: Check Knight Tour Configuration"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2596: Check Knight Tour Configuration in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OBht8NT_09c"
youtube_upload_date="2023-03-19"
youtube_thumbnail="https://i.ytimg.com/vi/OBht8NT_09c/maxresdefault.jpg"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2596.md" >}}
---
{{< youtube OBht8NT_09c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2597: The Number of Beautiful Subsets](https://grid47.xyz/leetcode/solution-2597-the-number-of-beautiful-subsets/) |
| --- |