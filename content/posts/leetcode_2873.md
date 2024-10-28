
+++
authors = ["Yasir"]
title = "Leetcode 2873: Maximum Value of an Ordered Triplet I"
date = "2016-12-17"
description = "Solution to Leetcode 2873"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, mxa = 0, mxab = 0;
        for(long a: nums) {
            res = max(res, mxab * a);
            mxab = max(mxab, mxa - a);
            mxa = max(mxa, a);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

