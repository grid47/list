
+++
authors = ["Yasir"]
title = "Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves"
date = "2020-09-11"
description = "Solution to Leetcode 1509"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        /* change one element to any other value in one move */
        /* get min diff between max and min value after performing atmost 3 moves */
        if(n < 5) return 0;
        sort(nums.begin(), nums.end());
        
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

