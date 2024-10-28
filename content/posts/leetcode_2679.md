
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2679: Sum in a Matrix"
date = "2017-06-29"
description = "Solution to Leetcode 2679"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-in-a-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        int res = 0;
        
        int m = nums.size(), n = nums[0].size();
        
        for(int i = 0; i < m; i++)
        sort(nums[i].rbegin(), nums[i].rend());
        
        for(int i = 0; i < n; i++) {
            int mx = nums[0][i];
            for(int j = 0; j < m; j++) {
                mx = max(mx, nums[j][i]);
            }
            res += mx;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

