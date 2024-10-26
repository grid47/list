
+++
authors = ["Yasir"]
title = "Leetcode 775: Global and Local Inversions"
date = "2022-09-13"
description = "Solution to Leetcode 775"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/global-and-local-inversions/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int cmax = 0, n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            cmax = max(cmax, nums[i]);
            if(cmax > nums[i + 2]) return false;
        }
        return true;
    }
};
{{< /highlight >}}

