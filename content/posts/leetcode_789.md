
+++
authors = ["Crafted by Me"]
title = "Leetcode 789: Escape The Ghosts"
date = "2022-09-05"
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/789.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

