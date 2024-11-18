
+++
authors = ["grid47"]
title = "Leetcode 764: Largest Plus Sign"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 764: Largest Plus Sign in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/764.webp"
youtube = "dOSQVrCtO9w"
youtube_upload_date="2021-09-09"
youtube_thumbnail="https://i.ytimg.com/vi/dOSQVrCtO9w/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/largest-plus-sign/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/764.webp" 
    alt="A grid where the largest plus sign is found, glowing softly as the shape is identified."
    caption="Solution to LeetCode 764: Largest Plus Sign Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, n));
        for(auto &m: mines)
        grid[m[0]][m[1]] = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0, k = n - 1, l = 0, r = 0, u = 0, d = 0; j < n; j++, k--) {
            grid[i][j] = min(grid[i][j], l = (grid[i][j] == 0? 0: l + 1));
            grid[i][k] = min(grid[i][k], r = (grid[i][k] == 0? 0: r + 1));
            grid[j][i] = min(grid[j][i], u = (grid[j][i] == 0? 0: u + 1));
            grid[k][i] = min(grid[k][i], d = (grid[k][i] == 0? 0: d + 1));
        }

        int res = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res = max(grid[i][j], res);

        return res;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/764.md" >}}
---
{{< youtube dOSQVrCtO9w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #767: Reorganize String](https://grid47.xyz/leetcode/solution-767-reorganize-string/) |
| --- |
