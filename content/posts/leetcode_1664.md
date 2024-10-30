
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1664: Ways to Make a Fair Array"
date = "2020-04-11"
description = "Solution to Leetcode 1664"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-make-a-fair-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int waysToMakeFair(vector<int>& nums) {

        vector<int> left(2, 0), right(2, 0);
        
        int n= nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
            right[i%2] += nums[i];
        
        for(int i = 0; i < n; i++) {
            right[i%2] -= nums[i];
            
            if(left[0] + right[1] == right[0] + left[1]) res++;
            
            left[i%2] += nums[i];
        }

        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

