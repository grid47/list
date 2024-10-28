
+++
authors = ["Yasir"]
title = "Leetcode 1857: Largest Color Value in a Directed Graph"
date = "2019-09-29"
description = "Solution to Leetcode 1857"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

