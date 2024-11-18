
+++
authors = ["grid47"]
title = "Leetcode 2341: Maximum Number of Pairs in Array"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2341: Maximum Number of Pairs in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-pairs-in-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  // even counter
  vector<int> numberOfPairs(vector<int>& nums) {
      int cnt[101] = {}, pairs = 0;
      for (int n : nums)
          pairs += ++cnt[n] % 2 == 0 ? 1 : 0;
      return { pairs, (int)nums.size() - pairs * 2 };
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2341.md" >}}
---
{{< youtube 9KeeDZ6tcy4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2342: Max Sum of a Pair With Equal Sum of Digits](https://grid47.xyz/leetcode/solution-2342-max-sum-of-a-pair-with-equal-sum-of-digits/) |
| --- |
