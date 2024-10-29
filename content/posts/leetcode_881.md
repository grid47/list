
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 881: Boats to Save People"
date = "2022-06-02"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/881.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

