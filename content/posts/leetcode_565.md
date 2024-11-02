
+++
authors = ["Crafted by Me"]
title = "Leetcode 565: Array Nesting"
date = "2022-04-16"
description = "Solution to Leetcode 565"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/array-nesting/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int mxsize = 0;
        for(int i = 0; i < nums.size(); i++) {
            int size = 0;
            for(int k = i; nums[k] >= 0; size++) {
                int ak = nums[k];
                nums[k] = -1;
                k = ak;
            }
            mxsize = max(size, mxsize);
        }
        return mxsize;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/565.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

