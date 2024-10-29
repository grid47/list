
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2527: Find Xor-Beauty of Array"
date = "2017-11-29"
description = "Solution to Leetcode 2527"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-xor-beauty-of-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        
        int tmp = 0;
        for(int it: nums)
            tmp ^= it;
        return tmp;
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

