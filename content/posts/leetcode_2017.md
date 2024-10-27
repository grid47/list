
+++
authors = ["Yasir"]
title = "Leetcode 2017: Grid Game"
date = "2019-04-21"
description = "Solution to Leetcode 2017"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/grid-game/description/)

---

**Code:**

{{< highlight html >}}
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

