
+++
authors = ["Crafted by Me"]
title = "Leetcode 624: Maximum Distance in Arrays"
date = "2023-02-17"
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/624.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

