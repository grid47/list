
+++
authors = ["Crafted by Me"]
title = "Leetcode 1857: Largest Color Value in a Directed Graph"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1857: Largest Color Value in a Directed Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> deg(n, 0);
        vector<vector<int>> grid(n);
        for(auto it : edges) {
            grid[it[0]].push_back(it[1]);
            deg[it[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(deg[i] == 0) {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int seen = n;
        int ans = 0;

        while(!q.empty()) {
            
            int x = q.front();
            q.pop();
            int mx = *max_element(dp[x].begin(), dp[x].end());
            ans = max(ans, mx);

            seen--;

            for(int nxt : grid[x]) {
                for(int i = 0; i < 26; i++) {
                    dp[nxt][i] = max(dp[nxt][i], dp[x][i] + (i == (colors[nxt] - 'a')));
                }
                if(--deg[nxt] == 0) q.push(nxt);

            }

        }

        return seen == 0? ans: -1;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1857.md" >}}
---
{{< youtube SGAHkdqtj5s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1858: Longest Word With All Prefixes](https://grid47.xyz/posts/leetcode_1858) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

