
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1283: Find the Smallest Divisor Given a Threshold"
date = "2021-04-25"
description = "Solution to Leetcode 1283"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6, m , sum;
        while(left < right) {
            m = (left + right) / 2;
            sum = 0;
            for(int i: nums) sum += (i + m - 1)/m;
            if(sum > threshold) 
            left = m + 1;
            else right = m;
        }
        return left;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

