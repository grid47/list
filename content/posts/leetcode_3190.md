
+++
authors = ["Yasir"]
title = "Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three"
date = "2016-02-04"
description = "Solution to Leetcode 3190"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) ans+=min(3-(nums[i]%3),nums[i]%3);
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

