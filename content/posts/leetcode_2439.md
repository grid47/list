
+++
authors = ["Yasir"]
title = "Leetcode 2439: Minimize Maximum of Array"
date = "2018-02-23"
description = "Solution to Leetcode 2439"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-maximum-of-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, (sum + i) / (i + 1));
        }
        return res;
    }
};
{{< /highlight >}}

