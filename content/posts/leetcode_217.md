
+++
authors = ["Crafted by Me"]
title = "Leetcode 217: Contains Duplicate"
date = "2024-03-30"
description = "In-depth solution and explanation for Leetcode 217: Contains Duplicate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/contains-duplicate/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> ma;
        for(int x: nums)
            if(ma.count(x)) return true;
        else ma[x] = 1;
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/217.md" >}}
---
{{< youtube SFMCxqSeM94 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #218: The Skyline Problem](https://grid47.xyz/posts/leetcode_218) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

