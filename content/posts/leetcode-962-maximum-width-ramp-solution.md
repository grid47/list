
+++
authors = ["grid47"]
title = "Leetcode 962: Maximum Width Ramp"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 962: Maximum Width Ramp in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
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
{{< youtube 3pTEJ1vzgSI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #963: Minimum Area Rectangle II](https://grid47.xyz/posts/leetcode-963-minimum-area-rectangle-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}