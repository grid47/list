
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2249: Count Lattice Points Inside a Circle"
date = "2018-09-03"
description = "Solution to Leetcode 2249"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-lattice-points-inside-a-circle/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& cir) {
        set<int> cnt;
        
        for(auto it: cir) {
            
            for(int i = it[0] - it[2]; i <= it[0] + it[2]; i++)
            for(int j = it[1] - it[2]; j <= it[1] + it[2]; j++)                
                if((i - it[0]) * (i - it[0]) + (j - it[1]) * (j - it[1]) <= (it[2] * it[2]))
                    cnt.insert(i * 1000 + j);
            
        }
        return cnt.size();
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

