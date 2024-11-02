
+++
authors = ["Crafted by Me"]
title = "Leetcode 283: Move Zeroes"
date = "2023-01-23"
description = "Solution to Leetcode 283"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/move-zeroes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
                swap(nums[i], nums[j]), j++;
        }
        while(j < nums.size())
            nums[j++] = 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/283.md" >}}
---
{{< youtube 39VJV4KVyi8 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

