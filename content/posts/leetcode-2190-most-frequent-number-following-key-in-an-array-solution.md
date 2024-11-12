
+++
authors = ["grid47"]
title = "Leetcode 2190: Most Frequent Number Following Key In an Array"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2190: Most Frequent Number Following Key In an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int mostFrequent(vector<int>& nums, int key) {
    int cnt[1001] = {}, res = 0;
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[res])
            res = nums[i];
    return res;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2190.md" >}}
---
{{< youtube 0KHTVvSX7CE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2191: Sort the Jumbled Numbers](https://grid47.xyz/posts/leetcode-2191-sort-the-jumbled-numbers-solution/) |
| --- |
