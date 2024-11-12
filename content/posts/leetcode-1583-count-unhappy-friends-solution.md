
+++
authors = ["grid47"]
title = "Leetcode 1583: Count Unhappy Friends"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1583: Count Unhappy Friends in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-unhappy-friends/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        vector<vector<int>> rnk(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < pref.size(); i++) {
            for(int j = 0; j < pref[i].size(); j++) {
                rnk[i][pref[i][j]] = j;                
            }
        }
        int cnt = 0;
        set<int> items;
        for(int i = 0; i < pairs.size(); i++) {
            for(int j = i + 1; j < pairs.size(); j++) {
                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];
                if((rnk[x][y] > rnk[x][u]) && (rnk[u][x] < rnk[u][v])) {
                    items.insert(x);
                    items.insert(u);
                }
                if((rnk[x][y] > rnk[x][v]) && (rnk[v][x] < rnk[v][u])) {
                    items.insert(x);
                    items.insert(v);
                }
                if((rnk[y][x] > rnk[y][u]) && (rnk[u][y] < rnk[u][v])) {
                    items.insert(y);
                    items.insert(u);
                }
                if((rnk[y][x] > rnk[y][v]) && (rnk[v][y] < rnk[v][u])) {
                    items.insert(y);
                    items.insert(v);
                }
            }
        }
        return items.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1583.md" >}}
---
{{< youtube GpJUwhzx258 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1584: Min Cost to Connect All Points](https://grid47.xyz/posts/leetcode-1584-min-cost-to-connect-all-points-solution/) |
| --- |
