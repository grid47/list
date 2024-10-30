
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1010: Pairs of Songs With Total Durations Divisible by 60"
date = "2022-01-25"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

