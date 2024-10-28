
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2391: Minimum Amount of Time to Collect Garbage"
date = "2018-04-13"
description = "Solution to Leetcode 2391"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[128] = {}, res = 0;        
        for(int i = 0; i < garbage.size(); i++) {
            res += garbage[i].size();
            for(char c : garbage[i])
                last[c] = i;
        }

        for(int j = 1; j < travel.size(); j++)
            travel[j] += travel[j - 1];
        
        for(int c : "PGM")
        if(last[c])
        res += travel[last[c] - 1];
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

