
+++
authors = ["Crafted by Me"]
title = "Leetcode 137: Single Number II"
date = "2024-06-18"
description = "Solution to Leetcode 137"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-number-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        int ones = 0, twos = 0;
        for(int i = 0; i < n; i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;            
        }
        return ones;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/137.md" >}}
- by gpt
        
---
{{< youtube cOFAmaMBVps >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

