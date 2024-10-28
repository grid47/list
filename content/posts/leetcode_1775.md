
+++
authors = ["Yasir"]
title = "Leetcode 1775: Equal Sum Arrays With Minimum Number of Operations"
date = "2019-12-20"
description = "Solution to Leetcode 1775"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() > 6*nums2.size() || 
            nums2.size() > 6*nums1.size())
            return -1;
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if(sum1 > sum2) return minOperations(nums2, nums1);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = nums2.size() - 1, ops = 0;
        while(sum2 > sum1) {

            if(j < 0 || i < nums1.size() && 6 - nums1[i] > nums2[j] - 1) {
                sum1 += 6 - nums1[i++];
            } else {
                sum2 -= nums2[j--] - 1;
            }

            ++ops;
        }
        return ops;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

