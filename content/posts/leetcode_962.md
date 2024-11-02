
+++
authors = ["Crafted by Me"]
title = "Leetcode 962: Maximum Width Ramp"
date = "2021-03-15"
description = "Solution to Leetcode 962"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-width-ramp/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        for(int i = 0; i < nums.size(); i++)
            if(s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        
        int res = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
            while(!s.empty() && nums[s.top()] <= nums[i])
                res = max(res, i - s.top()), s.pop();
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/962.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

