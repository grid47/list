
+++
authors = ["Crafted by Me"]
title = "Leetcode 2563: Count the Number of Fair Pairs"
date = "2017-10-26"
description = "Solution to Leetcode 2563"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long cnt = 0;
        for(int i = 0; i < n; i++) {
            int l = lower - nums[i];
            int r = upper - nums[i];
            int u = upper_bound(nums.begin(), nums.end(), r) - nums.begin();
            int b = max((int)(lower_bound(nums.begin(), nums.end(), l) - nums.begin()), i + 1);
            cnt +=  (u < b)? 0: u - b;
        }
        return cnt;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

