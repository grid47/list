
+++
authors = ["Yasir"]
title = "Leetcode 2210: Count Hills and Valleys in an Array"
date = "2018-10-10"
description = "Solution to Leetcode 2210"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countHillValley(vector<int>& nums) {
      int res = 0;
        for(int j = 0, i = 1; i < nums.size() - 1; i++)
          if ((nums[j] < nums[i] && nums[i] > nums[i + 1]) ||
              (nums[j] > nums[i] && nums[i] < nums[i + 1])) {
                res++;
                j = i;
              }
        return res;
    }
};
{{< /highlight >}}

