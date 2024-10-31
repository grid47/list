
+++
authors = ["Crafted by Me"]
title = "Leetcode 1503: Last Moment Before All Ants Fall Out of a Plank"
date = "2020-09-20"
description = "Solution to Leetcode 1503"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int mx = 0;
        for(int i = 0; i < right.size(); i++)
            mx = max(mx, n - right[i]);
        
        for(int i = 0; i < left.size(); i++)
            mx = max(mx, left[i]);        
        
        return mx;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

