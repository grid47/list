
+++
authors = ["grid47"]
title = "Leetcode 851: Loud and Rich"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 851: Loud and Rich in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/loud-and-rich/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    unordered_map<int, vector<int>> richer2;
    vector<int> res;
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for(auto v: richer) richer2[v[1]].push_back(v[0]);
        res = vector<int> (quiet.size(), -1);
        for(int i = 0; i < quiet.size(); i++) dfs(i, quiet);
        return res;
    }

    int dfs(int i, vector<int> &quiet) {
        if(res[i] >= 0) return res[i];
        res[i] = i;
        for(int j : richer2[i])
            if(quiet[res[i]] > quiet[dfs(j, quiet)]) res[i] = res[j];
        return res[i];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/851.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #852: Peak Index in a Mountain Array](https://grid47.xyz/posts/leetcode-852-peak-index-in-a-mountain-array-solution/) |
| --- |
