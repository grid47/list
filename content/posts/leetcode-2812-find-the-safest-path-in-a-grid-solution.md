
+++
authors = ["grid47"]
title = "Leetcode 2812: Find the Safest Path in a Grid"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2812: Find the Safest Path in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
    queue<array<int, 2>> q;
    int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j])
                q.push({i, j});
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
                g[x][y] = g[i][j] + 1;
                q.push({x, y});
            }
        }
    }
    priority_queue<array<int, 3>> pq;
    pq.push({g[0][0], 0, 0});
    while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
        auto [sf, i, j] = pq.top(); pq.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
                pq.push({min(sf, g[x][y]), x, y});
                g[x][y] *= -1; 
            }
        }
    }
    return pq.top()[0] - 1;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2812.md" >}}
---
{{< youtube -5mQcNiVWTs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2815: Max Pair Sum in an Array](https://grid47.xyz/posts/leetcode-2815-max-pair-sum-in-an-array-solution/) |
| --- |
