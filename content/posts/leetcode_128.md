
+++
authors = ["Crafted by Me"]
title = "Leetcode 128: Longest Consecutive Sequence"
date = "2024-06-27"
description = "In-depth solution and explanation for Leetcode 128: Longest Consecutive Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-consecutive-sequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int x: nums)
            s.insert(x);
        if(s.empty()) return 0;
        int mx = 1;
        for(int i = 0; i < nums.size(); i++) {
            int y = nums[i];
            int c = 1;
            if(!s.count(y + 1))
            while(s.count(y - 1)) {
                c++;
                y = y -1;
                mx = max(mx, c);
            }
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/128.md" >}}
---
{{< youtube P6RZZMu_maU >}}

"| 129: Sum Root to Leaf Numbers |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

