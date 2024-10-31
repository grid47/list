
+++
authors = ["Crafted by Me"]
title = "Leetcode 2971: Find Polygon With the Largest Perimeter"
date = "2016-09-13"
description = "Solution to Leetcode 2971"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n, 0);
        sum[0] = nums[0];
        for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
        for(int i = n - 1; i >= 2; i--)
            if(nums[i] < sum[i - 1])
                return sum[i];
        return -1;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

