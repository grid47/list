
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1438: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit"
date = "2020-11-22"
description = "Solution to Leetcode 1438"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

