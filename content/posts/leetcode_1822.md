
+++
authors = ["Yasir"]
title = "Leetcode 1822: Sign of the Product of an Array"
date = "2019-11-03"
description = "Solution to Leetcode 1822"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sign-of-the-product-of-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sgn = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                sgn = 0;
                break;
            } else if(nums[i] > 0) {
                
            } else if(nums[i] < 0) {
                sgn *= -1;
            }
        }
        return sgn;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

