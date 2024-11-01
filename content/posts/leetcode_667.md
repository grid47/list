
+++
authors = ["Crafted by Me"]
title = "Leetcode 667: Beautiful Arrangement II"
date = "2023-01-05"
description = "Solution to Leetcode 667"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/beautiful-arrangement-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for(int i = 1, j = n; i <= j; ) {
            if(k > 0) {
                res.push_back(k--%2? i++: j--);
            } else res.push_back(i++);
        }
        return res;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/667.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

