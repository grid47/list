
+++
authors = ["Yasir"]
title = "Leetcode 945: Minimum Increment to Make Array Unique"
date = "2022-03-27"
description = "Solution to Leetcode 945"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0, n = nums.size(), need = 0;
        for(int i = 0; i < n; i++) {
            res += max(need - nums[i], 0);
            need = max(nums[i], need) + 1;
        }
        return res;
    }
};
{{< /highlight >}}

