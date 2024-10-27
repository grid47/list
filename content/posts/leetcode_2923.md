
+++
authors = ["Yasir"]
title = "Leetcode 2923: Find Champion I"
date = "2016-10-27"
description = "Solution to Leetcode 2923"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-champion-i/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findChampion(vector<vector<int>>& g) {
        for (int i = 0; i < g.size(); ++i)
            if (accumulate(begin(g[i]), end(g[i]), 0) == g.size() - 1)
                return i;
        return -1;
    }
};
{{< /highlight >}}

