
+++
authors = ["Crafted by Me"]
title = "Leetcode 1144: Decrease Elements To Make Array Zigzag"
date = "2021-09-14"
description = "Solution to Leetcode 1144"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size(), left, right;
        vector<int> res(2, 0);
        for(int i = 0; i < n; i++) {

            left  = ( i     > 0 ) ? nums[i - 1] : 1001;
            right = ( i + 1 < n ) ? nums[i + 1] : 1001;

            res[i % 2] += max(0, nums[i] - min(left, right) + 1);
        }

        return min(res[0], res[1]);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

