
+++
authors = ["grid47"]
title = "Leetcode 553: Optimal Division"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 553: Optimal Division in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/optimal-division/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string s = "";
        if(nums.size() == 1) return to_string(nums[0]);
        if(nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);

        for(int i = 0; i < nums.size(); i++) {
            s += to_string(nums[i]) + "/";
            if(i == 0)
                s += "(";
        }
        s[s.size() -1] = ')';
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/553.md" >}}
---
{{< youtube SFNvfrvWxVQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #554: Brick Wall](https://grid47.xyz/posts/leetcode-554-brick-wall-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}