
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 396: Rotate Function"
date = "2023-09-30"
description = "Solution to Leetcode 396"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rotate-function/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0, fn = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            fn += i * nums[i];
        }

        long l = 1, r;
        long newfn = fn;

        while(l < n) {
            r = l + n - 1;
            long removed = (l - 1) *nums[l -1];
            long added = r * nums[r % n];

            newfn = newfn - removed + added - sum;

            fn = max(fn, newfn);
            l++;
        }
        return fn;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/396.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
