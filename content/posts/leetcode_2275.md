
+++
authors = ["Yasir"]
title = "Leetcode 2275: Largest Combination With Bitwise AND Greater Than Zero"
date = "2018-08-07"
description = "Solution to Leetcode 2275"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:

    int largestCombination(vector<int>& candidates) {
        int res = 0, cur = 0;
        for(int  i = 1; i < 10000000; i <<= 1) {
            cur = 0;
            for(int a: candidates)
                if(a & i)
                cur++;
            res = max(res, cur);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

