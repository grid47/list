
+++
authors = ["Yasir"]
title = "Leetcode 2321: Maximum Score Of Spliced Array"
date = "2018-06-22"
description = "Solution to Leetcode 2321"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

