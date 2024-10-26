
+++
authors = ["Yasir"]
title = "Leetcode 789: Escape The Ghosts"
date = "2022-08-30"
description = "Solution to Leetcode 789"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/escape-the-ghosts/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& gs, vector<int>& t) {
        int d = abs(t[0]) + abs(t[1]);
        for(auto it: gs)
        if(d >= abs(it[0] - t[0]) + abs(it[1] - t[1]))
        return false;
        return true;
    }
};
{{< /highlight >}}

