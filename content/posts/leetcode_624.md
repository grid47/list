
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 624: Maximum Distance in Arrays"
date = "2023-02-13"
description = "Solution to Leetcode 624"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-distance-in-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, mn = 10000, mx = -10000;
        for (auto& a : arrays) {
            res = max(res, max(a.back()-mn, mx-a.front()));
            mn = min(mn, a.front()), mx = max(mx, a.back());
        }
        return res;        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

