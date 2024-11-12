
+++
authors = ["grid47"]
title = "Leetcode 1785: Minimum Elements to Add to Form a Given Sum"
date = "2024-05-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1785: Minimum Elements to Add to Form a Given Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        for(int x: nums)
            sum += x;
        long diff = abs(goal - sum);
        if(diff % limit == 0) return diff/limit;
        else return diff/limit + 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1785.md" >}}
---
{{< youtube UDAGlLHIeT4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1786: Number of Restricted Paths From First to Last Node](https://grid47.xyz/posts/leetcode-1786-number-of-restricted-paths-from-first-to-last-node-solution/) |
| --- |
