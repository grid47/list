
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2871: Split Array Into Maximum Number of Subarrays"
date = "2016-12-19"
description = "Solution to Leetcode 2871"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0, cur = 0;
        for (int n : nums) {
            cur = cur == 0 ? n : cur & n;
            res += cur == 0;
        }
        return max(1, res);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

