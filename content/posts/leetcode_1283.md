
+++
authors = ["Yasir"]
title = "Leetcode 1283: Find the Smallest Divisor Given a Threshold"
date = "2021-04-24"
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

{{< highlight html >}}
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

