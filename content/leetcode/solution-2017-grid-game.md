
+++
authors = ["grid47"]
title = "Leetcode 2017: Grid Game"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2017: Grid Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "N4wDSOw65hI"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/grid-game/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottom = 0;
        int n = grid[0].size();
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            top -= grid[0][i];
            ans = min(ans, max(top, bottom));
            bottom+= grid[1][i];
      }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2017.md" >}}
---
{{< youtube N4wDSOw65hI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2018: Check if Word Can Be Placed In Crossword](https://grid47.xyz/leetcode/solution-2018-check-if-word-can-be-placed-in-crossword/) |
| --- |
