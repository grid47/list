
+++
authors = ["grid47"]
title = "Leetcode 2660: Determine the Winner of a Bowling Game"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2660: Determine the Winner of a Bowling Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int sc1 = 0, sc2 = 0;
        int n = p1.size();
        for(int i = 0; i < n; i++) {
            if(i > 1 && (p1[i - 1] == 10 || p1[i - 2] == 10)) {
                sc1 += 2 * p1[i];
            } else if(i > 0 && p1[i - 1] == 10){
                sc1 += 2 * p1[i];                
            }
            else sc1 += p1[i];
            if(i > 1 && (p2[i - 1] == 10 || p2[i - 2] == 10)) {
                sc2 += 2 * p2[i];
            }else if(i > 0 && p2[i - 1] == 10){
                sc2 += 2 * p2[i];                
            } else sc2 += p2[i];            
        }
        if(sc1 > sc2) return 1;
        if(sc2 > sc1) return 2;
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2660.md" >}}
---
{{< youtube UzLjzmjhVqs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2661: First Completely Painted Row or Column](https://grid47.xyz/leetcode/solution-2661-first-completely-painted-row-or-column/) |
| --- |
