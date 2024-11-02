
+++
authors = ["Crafted by Me"]
title = "Leetcode 977: Squares of a Sorted Array"
date = "2021-02-28"
description = "Solution to Leetcode 977"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/squares-of-a-sorted-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1;
        int ll, rr;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ll = nums[l] * nums[l];
            rr = nums[r] * nums[r];
            if(ll < rr) ans[i] = rr, r--;
            else ans[i] = ll, l++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/977.md" >}}
---
{{< youtube z0InhrjK3es >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

