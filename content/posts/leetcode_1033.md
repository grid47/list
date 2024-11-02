
+++
authors = ["Crafted by Me"]
title = "Leetcode 1033: Moving Stones Until Consecutive"
date = "2021-01-03"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

