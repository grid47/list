
+++
authors = ["Crafted by Me"]
title = "Leetcode 2477: Minimum Fuel Cost to Report to the Capital"
date = "2018-01-21"
description = "In-depth solution and explanation for Leetcode 2477: Minimum Fuel Cost to Report to the Capital in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

