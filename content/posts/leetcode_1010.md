
+++
authors = ["Crafted by Me"]
title = "Leetcode 1010: Pairs of Songs With Total Durations Divisible by 60"
date = "2022-01-27"
description = "Solution to Leetcode 1010"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60, 0);
        int res = 0;
        for(int t: time) {
            res += c[(600 - t)%60];
            c[t%60] += 1;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1010.md" >}}
---
{{< youtube gM5Wu42UTQk >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

