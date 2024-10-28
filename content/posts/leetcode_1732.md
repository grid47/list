
+++
authors = ["Yasir"]
title = "Leetcode 1732: Find the Highest Altitude"
date = "2020-02-01"
description = "Solution to Leetcode 1732"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-highest-altitude/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0;
        int cur = 0;
        for(int x: gain) {
            cur += x;
            mx = max(mx, cur);
        }
        return mx;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

