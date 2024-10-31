
+++
authors = ["Crafted by Me"]
title = "Leetcode 2270: Number of Ways to Split Array"
date = "2018-08-15"
description = "Solution to Leetcode 2270"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-split-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int waysToSplitArray(vector<int>& in) {
        
        
        // partial_sum(nums.begin(), nums.end(), nums.begin());
        
        int n = in.size(), res = 0;

        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
        nums[i] = (i == 0) ? in[0] : nums[i - 1] + in[i];
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] >= nums[n - 1] - nums[i]) res++;
        }
        
        return res;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

