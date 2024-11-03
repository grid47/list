
+++
authors = ["Crafted by Me"]
title = "Leetcode 2321: Maximum Score Of Spliced Array"
date = "2018-06-26"
description = "In-depth solution and explanation for Leetcode 2321: Maximum Score Of Spliced Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-of-spliced-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        int sum1 = 0, sum2 = 0, ans;
        for(int x: nums1) sum1 += x;
        for(int x: nums2) sum2 += x;

        ans = max(sum1, sum2);

        int fst = 0, scd = 0, mx1 = 0, mx2 = 0;

        for(int i = 0; i < n; i++) {
            fst += (nums2[i] - nums1[i]);
            scd += (nums1[i] - nums2[i]);

            mx1 = max(mx1, fst);
            mx2 = max(mx2, scd);

            if(fst < 0) fst = 0;
            if(scd < 0) scd = 0;
        }

        ans = max(ans, sum1 + mx1);
        ans = max(ans, sum2 + mx2);        

        return ans;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2322: Minimum Score After Removals on a Tree](grid47.xyz/leetcode_2322) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

