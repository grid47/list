
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 822: Card Flipping Game"
date = "2022-07-30"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

