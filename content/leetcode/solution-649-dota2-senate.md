
+++
authors = ["grid47"]
title = "Leetcode 649: Dota2 Senate"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 649: Dota2 Senate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/dota2-senate/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/649.webp" 
    alt="A series of characters where the senate is divided and illuminated by those voting for or against, softly glowing."
    caption="Solution to LeetCode 649: Dota2 Senate Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
{{< youtube zZA5KskfMuQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #652: Find Duplicate Subtrees](https://grid47.xyz/leetcode/solution-652-find-duplicate-subtrees/) |
| --- |
