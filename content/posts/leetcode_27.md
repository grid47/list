
+++
authors = ["Crafted by Me"]
title = "Leetcode 27: Remove Element"
date = "2023-10-06"
description = "Solution to Leetcode 27"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-element/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        
        for(int node: nums)
            if(node != val)
            {
                nums[i] = node;
                i++;
            }
        
        return i;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/27.md" >}}
---
{{< youtube Pcd1ii9P9ZI >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

