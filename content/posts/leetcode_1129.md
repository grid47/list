
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1129: Shortest Path with Alternating Colors"
date = "2021-09-28"
description = "Solution to Leetcode 1129"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-path-with-alternating-colors/description/)

---
{{< youtube VaW0deOb2aQ >}}
**Code:**

{{< highlight cpp >}}
class Solution {
    public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &greenEdges) {

        vector<vector<int>> gph(n);
        vector<vector<vector<int>>> grid(2, gph);

        for(int i = 0; i < redEdges.size(); i++)
            grid[0][redEdges[i][0]].push_back(redEdges[i][1]);

        for(int i = 0; i < greenEdges.size(); i++)
            grid[1][greenEdges[i][0]].push_back(greenEdges[i][1]);

        vector<vector<int>> len(2, vector<int>(n, 2 * n));

        queue<vector<int>> q;

        len[0][0] = 0;
        len[1][0] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it[0], color = it[1];
            for(int nxt: grid[1 - color][node]) {
                if(len[1 - color][nxt] == 2 * n) {
                    len[1 - color][nxt] = len[color][node] + 1;
                    q.push({nxt, 1 - color});
                }
            }
        }

        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[i] = min(len[0][i], len[1][i]);
            if(res[i] == 2 * n) res[i] = -1;
        }

        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

