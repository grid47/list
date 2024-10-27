
+++
authors = ["Yasir"]
title = "Leetcode 1818: Minimum Absolute Sum Difference"
date = "2019-11-06"
description = "Solution to Leetcode 1818"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-sum-difference/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        set<int> sel(begin(nums1), end(nums1));

        long gain = 0, res = 0;
        for(int i = 0; i < n; i++) {
            long og = abs(nums1[i] - nums2[i]);
            res += og;
            if (gain < og) {
                auto num = sel.lower_bound(nums2[i]);
                if (num !=   end(sel)) gain = max(gain, og - abs(*num       - nums2[i]));
                if (num != begin(sel)) gain = max(gain, og - abs(*prev(num) - nums2[i]));
            }
        }

        return (res - gain) % 1000000007;
    }
};
{{< /highlight >}}

