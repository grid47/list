
+++
authors = ["Crafted by Me"]
title = "Leetcode 2341: Maximum Number of Pairs in Array"
date = "2018-06-05"
description = "Solution to Leetcode 2341"
tags = [
    
]
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



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

