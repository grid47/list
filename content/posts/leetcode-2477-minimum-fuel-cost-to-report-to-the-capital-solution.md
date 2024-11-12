
+++
authors = ["grid47"]
title = "Leetcode 2477: Minimum Fuel Cost to Report to the Capital"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2477: Minimum Fuel Cost to Report to the Capital in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long ans;
    int s;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> graph(roads.size()+1);s = seats;
        for (vector<int> r: roads){
            graph[r[0]].push_back(r[1]);
                      graph[r[1]].push_back(r[0]);
        }
        dfs(0, 0, graph);
        return ans;
    }
    int dfs(int i, int prev, vector<vector<int>> &graph) {
        int people = 1;
        for(int &x: graph[i]) {
            if (x == prev) continue;
            people += dfs(x,i, graph);
        }
        if(i != 0) ans += (s + people - 1)/s;
        return people;
     }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2477.md" >}}
---
{{< youtube I3lnDUIzIG4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2481: Minimum Cuts to Divide a Circle](https://grid47.xyz/posts/leetcode-2481-minimum-cuts-to-divide-a-circle-solution/) |
| --- |
