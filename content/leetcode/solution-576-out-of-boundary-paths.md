
+++
authors = ["grid47"]
title = "Leetcode 576: Out of Boundary Paths"
date = "2024-09-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 576: Out of Boundary Paths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/576.webp"
youtube = "Bg5CLRqtNmk"
youtube_upload_date="2024-01-26"
youtube_thumbnail="https://i.ytimg.com/vi/Bg5CLRqtNmk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/out-of-boundary-paths/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/576.webp" 
    alt="A grid where paths leading out of bounds are highlighted and softly glowing."
    caption="Solution to LeetCode 576: Out of Boundary Paths Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = (int) 1e9 + 7;
public:
    int findPaths(int m, int n, int mv, int i, int j) {
        
        vector<vector<vector<int>>> mm(mv + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        
        return dfs(m, n, mv, 0, i, j, mm);
        
    }
    
    int dfs(int m, int n, int mx, int mv, int x, int y, vector<vector<vector<int>>> & mm) {

        if (x < 0 || y < 0 || x >= m || y >= n) return 1;
        if (mv == mx)                           return 0;
        if (mm[mv][x][y] > -1)                  return mm[mv][x][y];

        int res = 0;
        res = ( res + dfs(m, n, mx, mv + 1, x + 1, y, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x - 1, y, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x, y + 1, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x, y - 1, mm) ) % mod;

        return mm[mv][x][y] = (res % mod);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/576.md" >}}
---
{{< youtube Bg5CLRqtNmk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #581: Shortest Unsorted Continuous Subarray](https://grid47.xyz/leetcode/solution-581-shortest-unsorted-continuous-subarray/) |
| --- |