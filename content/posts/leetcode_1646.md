
+++
authors = ["Yasir"]
title = "Leetcode 1646: Get Maximum in Generated Array"
date = "2020-04-27"
description = "Solution to Leetcode 1646"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/get-maximum-in-generated-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
    public int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        int[] nums = new int[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        int max = 1;
        for(int i = 1; 2 * i + 1 < n + 1; i++) {
            nums[2 * i]     = nums[i];
            max = Math.max(nums[2 * i],     max);
            nums[2 * i + 1] = nums[i] + nums[i + 1];
            max = Math.max(nums[2 * i + 1], max);
        }
        return max;
    }
}
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

