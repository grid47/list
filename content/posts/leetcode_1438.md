
+++
authors = ["Crafted by Me"]
title = "Leetcode 1438: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit"
date = "2020-11-25"
description = "In-depth solution and explanation for Leetcode 1438: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
            while(!ms.empty() && *ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[j++]));
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1438.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1439: Find the Kth Smallest Sum of a Matrix With Sorted Rows](https://grid47.xyz/posts/leetcode_1439) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

