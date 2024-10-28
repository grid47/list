
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 136: Single Number"
date = "2024-06-15"
description = "Solution to Leetcode 136"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int y: nums)
            x ^= y;
        return x;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

