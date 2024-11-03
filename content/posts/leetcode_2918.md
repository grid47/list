
+++
authors = ["Crafted by Me"]
title = "Leetcode 2918: Minimum Equal Sum of Two Arrays After Replacing Zeros"
date = "2016-11-06"
description = "In-depth solution and explanation for Leetcode 2918: Minimum Equal Sum of Two Arrays After Replacing Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
        for(int num: nums1) cnt1 += num == 0, sum1 += num;
        for(int num: nums2) cnt2 += num == 0, sum2 += num;

        if(cnt1 == 0 && cnt2 + sum2 > sum1 ||
            cnt2 == 0 && cnt1 + sum1 > sum2)
                return -1;

        return max(sum1 + cnt1, sum2 + cnt2);

    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

