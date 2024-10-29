
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1577: Number of Ways Where Square of Number Is Equal to Product of Two Numbers"
date = "2020-07-06"
description = "Solution to Leetcode 1577"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        long res = 0;

        for(int v: nums1)
            res += twoProd((long)v * v, nums2);
        for(int v: nums2)
            res += twoProd((long)v * v, nums1);

        return res;
    }
    
    
    long twoProd(long i, vector<int> &nums) {
        map<long, long> mp;
        
        int cnt = 0;
        for(int n : nums) {
            if(i % n == 0)
                cnt += mp[i / n];
            mp[n]++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

