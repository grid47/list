
+++
authors = ["Yasir"]
title = "Leetcode 2477: Minimum Fuel Cost to Report to the Capital"
date = "2018-01-17"
description = "Solution to Leetcode 2477"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

