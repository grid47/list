
+++
authors = ["Crafted by Me"]
title = "Leetcode 477: Total Hamming Distance"
date = "2023-07-14"
description = "Solution to Leetcode 477"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/total-hamming-distance/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size();
        for(int i = 0; i < 32; i++) {
            int bitCnt = 0;
            for(int j = 0; j < nums.size(); j++)
                bitCnt += (nums[j] >> i) & 1;
            
            total += bitCnt * (n - bitCnt);
        }
        return total;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/477.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

