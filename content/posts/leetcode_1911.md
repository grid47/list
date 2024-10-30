
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1911: Maximum Alternating Subsequence Sum"
date = "2019-08-08"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
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
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

