
+++
authors = ["Yasir"]
title = "Leetcode 797: All Paths From Source to Target"
date = "2022-08-22"
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

**Code:**

{{< highlight html >}}
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

