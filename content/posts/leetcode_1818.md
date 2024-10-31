
+++
authors = ["Crafted by Me"]
title = "Leetcode 1818: Minimum Absolute Sum Difference"
date = "2019-11-10"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

