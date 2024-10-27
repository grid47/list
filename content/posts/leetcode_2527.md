
+++
authors = ["Yasir"]
title = "Leetcode 2527: Find Xor-Beauty of Array"
date = "2017-11-27"
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

{{< highlight html >}}
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

