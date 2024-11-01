
+++
authors = ["Crafted by Me"]
title = "Leetcode 822: Card Flipping Game"
date = "2022-08-03"
description = "Solution to Leetcode 822"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/card-flipping-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for(int i = 0; i < fronts.size(); i++) if(fronts[i] == backs[i]) same.insert(fronts[i]);
        int res = 3000;
        for(auto &num: fronts) if(!same.count(num)) res = min(res, num);
        for(auto &num: backs)  if(!same.count(num)) res = min(res, num);        
        return res % 3000;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/822.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

