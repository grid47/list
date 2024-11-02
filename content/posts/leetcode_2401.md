
+++
authors = ["Crafted by Me"]
title = "Leetcode 2401: Longest Nice Subarray"
date = "2017-04-06"
description = "Solution to Leetcode 2401"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-nice-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1, AND = 0, n = nums.size(), j = 0;
        for(int i = 0; i < n; i++) {
            while(((AND & nums[i]) > 0)) {
                AND ^= nums[j++];
            }
            AND |= nums[i];
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

