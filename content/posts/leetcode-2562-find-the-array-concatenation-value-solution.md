
+++
authors = ["grid47"]
title = "Leetcode 2562: Find the Array Concatenation Value"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2562: Find the Array Concatenation Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-array-concatenation-value/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  long long findTheArrayConcVal(vector<int>& nums) {
      long long res = 0, sz = nums.size();
      for (int i = 0, j = sz - 1; i <= j; ++i, --j)
          if (i < j)
              res += nums[i] * pow(10, (int)log10(nums[j]) + 1) + nums[j];
          else
              res += nums[i];
      return res;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2562.md" >}}
---
{{< youtube OgX8lEhgW9g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2563: Count the Number of Fair Pairs](https://grid47.xyz/posts/leetcode-2563-count-the-number-of-fair-pairs-solution/) |
| --- |
