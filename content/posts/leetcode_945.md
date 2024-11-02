
+++
authors = ["Crafted by Me"]
title = "Leetcode 945: Minimum Increment to Make Array Unique"
date = "2021-04-01"
description = "Solution to Leetcode 945"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0, n = nums.size(), need = 0;
        for(int i = 0; i < n; i++) {
            res += max(need - nums[i], 0);
            need = max(nums[i], need) + 1;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/945.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

