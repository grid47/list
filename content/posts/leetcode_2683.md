
+++
authors = ["Crafted by Me"]
title = "Leetcode 2683: Neighboring Bitwise XOR"
date = "2016-06-28"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

