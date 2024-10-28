
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2859: Sum of Values at Indices With K Set Bits"
date = "2016-12-31"
description = "Solution to Leetcode 2859"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
      int res = 0;

      for(int i = 0; i < nums.size(); i++) {
        int c = 0;
        int copy = i;
        while(copy) {
            c += copy & 1;
            copy >>= 1;
        }
        if(c == k) {
            res += nums[i];
        }
      }

      return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

