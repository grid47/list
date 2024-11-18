
+++
authors = ["grid47"]
title = "Leetcode 2824: Count Pairs Whose Sum is Less than Target"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2824: Count Pairs Whose Sum is Less than Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int countPairs(vector<int>& nums, int target) {
      int ans = 0;
      for(int i = 0; i < nums.size(); ++i){
          for(int j = i + 1; j < nums.size(); ++j){
              if(nums[i] + nums[j] < target) ans++;
          }
      }
      return ans;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2824.md" >}}
---
{{< youtube Xe1teNERwSY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2825: Make String a Subsequence Using Cyclic Increments](https://grid47.xyz/leetcode/solution-2825-make-string-a-subsequence-using-cyclic-increments/) |
| --- |
