
+++
authors = ["Crafted by Me"]
title = "Leetcode 1208: Get Equal Substrings Within Budget"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1208: Get Equal Substrings Within Budget in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/get-equal-substrings-within-budget/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int equalSubstring(string s, string t, int mxc) {
        vector<int> nums(s.size(), 0);
        for(int i = 0; i < s.size(); i++) {
            nums[i] = abs(s[i] - t[i]);
        }
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            mxc -= nums[i];
            while(mxc < 0) {
                mxc += nums[j++];
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1208.md" >}}
---
{{< youtube 3lsT1Le526U >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1209: Remove All Adjacent Duplicates in String II](https://grid47.xyz/posts/leetcode_1209) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

