
+++
authors = ["Yasir"]
title = "Leetcode 1911: Maximum Alternating Subsequence Sum"
date = "2019-08-06"
description = "Solution to Leetcode 1911"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-alternating-subsequence-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        long long odd = 0, even = 0;

        for(int num : nums) {
            even = max(even, odd + num);
            odd = even - num;
        }

        return even;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

