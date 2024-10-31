
+++
authors = ["Crafted by Me"]
title = "Leetcode 2660: Determine the Winner of a Bowling Game"
date = "2017-07-21"
description = "Solution to Leetcode 2660"
tags = [
    
]
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



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

