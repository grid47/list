
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 797: All Paths From Source to Target"
date = "2022-08-26"
description = "Solution to Leetcode 797"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/all-paths-from-source-to-target/description/)

---
{{< youtube MQU2IIWwaOg >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<pair<int, vector<int>>> q;
        q.push({0, {0}});
        while(!q.empty()) {
            int x = q.front().first;
            vector<int> t = q.front().second;
            q.pop();
            if(x == graph.size() - 1) ans.push_back(t);
            for(int k: graph[x]) {
                t.push_back(k);
                q.push({k, t});
                t.pop_back();
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/797.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

