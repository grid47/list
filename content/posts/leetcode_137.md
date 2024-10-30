
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 137: Single Number II"
date = "2024-06-16"
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
{{< youtube cOFAmaMBVps >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

