
+++
authors = ["Crafted by Me"]
title = "Leetcode 649: Dota2 Senate"
date = "2023-01-23"
description = "In-depth solution and explanation for Leetcode 649: Dota2 Senate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/dota2-senate/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string predictPartyVictory(string sen) {
        
        queue<int> q1, q2;
        int n = sen.size();
        for(int i = 0; i < sen.size(); i++)
        (sen[i] == 'R')? q1.push(i) : q2.push(i);

        while(!q1.empty() && !q2.empty()) {
            int r = q1.front(); q1.pop();
            int l = q2.front(); q2.pop();
            
            (r < l) ? q1.push(r + n) : q2.push(l + n);
            
        }
        return q1.size() > q2.size()  ?  "Radiant" : "Dire" ;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/649.md" >}}
---


| Next : [LeetCode #650: 2 Keys Keyboard](grid47.xyz/leetcode_650) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

