
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 881: Boats to Save People"
date = "2022-06-01"
description = "Solution to Leetcode 881"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/boats-to-save-people/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int lo = 0, hi = people.size() - 1;
        int boats = 0;
        while(lo <= hi) {
            
            if(people[lo] + people[hi] <= limit) {
                lo += 1;
                hi -= 1;
            } else hi -= 1;
            
            boats++;
        }
        
        return boats;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

