
+++
authors = ["Yasir"]
title = "Leetcode 649: Dota2 Senate"
date = "2023-01-18"
description = "Solution to Leetcode 649"
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

{{< highlight html >}}
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

