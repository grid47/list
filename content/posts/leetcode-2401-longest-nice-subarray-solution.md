
+++
authors = ["grid47"]
title = "Leetcode 2401: Longest Nice Subarray"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2401: Longest Nice Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Sliding Window"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2401.md" >}}
---
{{< youtube DJYpUQy3iME >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2402: Meeting Rooms III](https://grid47.xyz/posts/leetcode-2402-meeting-rooms-iii-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
