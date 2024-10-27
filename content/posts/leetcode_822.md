
+++
authors = ["Yasir"]
title = "Leetcode 822: Card Flipping Game"
date = "2022-07-29"
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

{{< highlight html >}}
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

