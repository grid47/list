
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 789: Escape The Ghosts"
date = "2022-09-01"
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

{{< highlight cpp >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

