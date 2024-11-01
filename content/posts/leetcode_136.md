
+++
authors = ["Crafted by Me"]
title = "Leetcode 136: Single Number"
date = "2024-06-19"
description = "Solution to Leetcode 136"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int y: nums)
            x ^= y;
        return x;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/136.md" >}}
- by gpt
        
---
{{< youtube mriHA5vEh0A >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

