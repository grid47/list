
+++
authors = ["Crafted by Me"]
title = "Leetcode 1775: Equal Sum Arrays With Minimum Number of Operations"
date = "2019-12-24"
description = "In-depth solution and explanation for Leetcode 1775: Equal Sum Arrays With Minimum Number of Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---

| Next : [LeetCode #1776: Car Fleet II](https://grid47.xyz/posts/leetcode_1776) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

