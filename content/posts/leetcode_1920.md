
+++
authors = ["Yasir"]
title = "Leetcode 1920: Build Array from Permutation"
date = "2019-07-28"
description = "Solution to Leetcode 1920"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/build-array-from-permutation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

