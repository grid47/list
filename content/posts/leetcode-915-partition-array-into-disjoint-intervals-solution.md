
+++
authors = ["grid47"]
title = "Leetcode 915: Partition Array into Disjoint Intervals"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 915: Partition Array into Disjoint Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int max_i, cur, ans = 1;
        max_i = cur = nums[0];
        
        for(int i = 1; i < n; i++) {
            if(nums[i] < max_i) {
                max_i = cur;
                ans = i + 1;
            } else if (nums[i] > cur)
                cur = nums[i];
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/915.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #916: Word Subsets](https://grid47.xyz/posts/leetcode-916-word-subsets-solution/) |
| --- |
