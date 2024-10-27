
+++
authors = ["Yasir"]
title = "Leetcode 2221: Find Triangular Sum of an Array"
date = "2018-09-29"
description = "Solution to Leetcode 2221"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-triangular-sum-of-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);        
        for(int i = n; i > 1; i--) {
            int k = i - 1;
            for(int j = k - 1; j >= 0; j--)
                arr[j] = (nums[j] % 10 + nums[j + 1] % 10) % 10;
            
            nums = arr;
        }
        
        return nums[0];
    }
};
{{< /highlight >}}

