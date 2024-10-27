
+++
authors = ["Yasir"]
title = "Leetcode 977: Squares of a Sorted Array"
date = "2022-02-24"
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

{{< highlight html >}}
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

