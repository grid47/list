
+++
authors = ["Crafted by Me"]
title = "Leetcode 396: Rotate Function"
date = "2022-10-02"
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
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

