
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2869: Minimum Operations to Collect Elements"
date = "2016-12-22"
description = "Solution to Leetcode 2869"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-collect-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt[51] = {}, i = nums.size() - 1;
        for (int found = 0; found < k; --i)
            if (nums[i] <= k)
                found += cnt[nums[i]]++ == 0;
        return nums.size() - i - 1;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

