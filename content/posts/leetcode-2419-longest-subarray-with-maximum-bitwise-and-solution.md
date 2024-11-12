
+++
authors = ["grid47"]
title = "Leetcode 2419: Longest Subarray With Maximum Bitwise AND"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2419: Longest Subarray With Maximum Bitwise AND in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x = *max_element(nums.begin(), nums.end());
        int len = 0, ans = 0;
        for(int ele: nums) {
            if(ele == x) {
                ans = max(ans, ++len);
            } else len = 0;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2419.md" >}}
---
{{< youtube N8lRlRWA_1Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2420: Find All Good Indices](https://grid47.xyz/posts/leetcode-2420-find-all-good-indices-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
