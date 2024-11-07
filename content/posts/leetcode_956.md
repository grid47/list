
+++
authors = ["Crafted by Me"]
title = "Leetcode 956: Tallest Billboard"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 956: Tallest Billboard in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/tallest-billboard/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rods;
    vector<map<int, int>> mem;
    
    int dp(int idx, int diff) {
        if(idx == rods.size()) return diff == 0? 0: INT_MIN;
        if(mem[idx].count(diff)) return mem[idx][diff];

        int ans = dp(idx + 1, diff);
        ans = max(ans, rods[idx] + dp(idx + 1, diff + rods[idx]));
        ans = max(ans, (rods[idx]> diff? rods[idx] - diff:0) + dp(idx + 1, abs(diff - rods[idx])));

        return mem[idx][diff] = ans;
    }
    
    int tallestBillboard(vector<int>& rods) {
        this->rods =rods;
        mem.resize(rods.size());
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/956.md" >}}
---
{{< youtube nAqt8y6wwVA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #957: Prison Cells After N Days](https://grid47.xyz/posts/leetcode_957) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
