
+++
authors = ["Yasir"]
title = "Leetcode 2683: Neighboring Bitwise XOR"
date = "2017-06-24"
description = "Solution to Leetcode 2683"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/neighboring-bitwise-xor/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool doesValidArrayExist(vector<int>& nums) {
        int n = nums.size();
        // same 0 0
        
        int fst = 0, scd = 1;
        for(int i = 0; i < n; i++) {
            fst ^= nums[i];
            scd ^= nums[i];
        }
        if(fst == 0 || scd == 1) return true;
        return false;
        // same 1 1
        // different 1 0
        // different 0 1        
    }
};
{{< /highlight >}}

