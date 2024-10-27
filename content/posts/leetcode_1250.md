
+++
authors = ["Yasir"]
title = "Leetcode 1250: Check If It Is a Good Array"
date = "2021-05-27"
description = "Solution to Leetcode 1250"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-it-is-a-good-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd = nums[0];
        for(int i = 1; i < nums.size(); i++)
            gcd = __gcd(gcd, nums[i]);
        return gcd == 1;
    }
};
{{< /highlight >}}

