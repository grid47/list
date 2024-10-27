
+++
authors = ["Yasir"]
title = "Leetcode 2951: Find the Peaks"
date = "2016-09-29"
description = "Solution to Leetcode 2951"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-peaks/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        vector<int> res;
        for(int i = 1; i < nums.size() - 1; i++) {
            if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
                res.push_back(i);            
        }

        return res;
    }
};
{{< /highlight >}}

