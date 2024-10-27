
+++
authors = ["Yasir"]
title = "Leetcode 1557: Minimum Number of Vertices to Reach All Nodes"
date = "2020-07-24"
description = "Solution to Leetcode 1557"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ca(n, 0);
        vector<int> ans;
        for(auto e: edges) {
            ca[e[1]]++;
        }
        for(int i = 0; i< n ; i++)
        if(ca[i] == 0) ans.push_back(i);
        return ans;
    }
};
{{< /highlight >}}

