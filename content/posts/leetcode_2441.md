
+++
authors = ["Yasir"]
title = "Leetcode 2441: Largest Positive Integer That Exists With Its Negative"
date = "2018-02-22"
description = "Solution to Leetcode 2441"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
int findMaxK(vector<int>& nums) {
    int arr[2001] = {}, res = -1;
    for (int n : nums) {
        if (arr[-n + 1000])
            res = max(res, abs(n));
        ++arr[n + 1000];        
    }
    return res;
}
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

