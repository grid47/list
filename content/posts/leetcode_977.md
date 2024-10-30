
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 977: Squares of a Sorted Array"
date = "2022-02-27"
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
{{< youtube z0InhrjK3es >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

