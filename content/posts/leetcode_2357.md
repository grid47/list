
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2357: Make Array Zero by Subtracting Equal Amounts"
date = "2018-05-19"
description = "Solution to Leetcode 2357"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx = 0, res = 0, diff;
        for(int i = 0; i < nums.size(); i++) {
            if(mx < nums[i]) {
                mx = nums[i];
                res++;
            }
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

