
+++
authors = ["Yasir"]
title = "Leetcode 1033: Moving Stones Until Consecutive"
date = "2021-12-31"
description = "Solution to Leetcode 1033"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/moving-stones-until-consecutive/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> s {a, b, c};
        sort(s.begin(), s.end());
        
        if(s[2]-s[0] == 2) return {0, 0};
        
        
        
        return {min(s[1]- s[0], s[2]-s[1]) <= 2? 1 : 2, s[2] - s[0] - 2 };
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

