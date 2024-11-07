
+++
authors = ["Crafted by Me"]
title = "Leetcode 2154: Keep Multiplying Found Values by Two"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2154: Keep Multiplying Found Values by Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int findFinalValue(vector<int>& nums, int o) {
        int h[1001]={};
        for(auto i:nums) h[i]++;
		
        while(o<=1000 && h[o])
            o*=2;
        
        return o;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2154.md" >}}
---
{{< youtube b-6Wf-ZShQQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2155: All Divisions With the Highest Score of a Binary Array](https://grid47.xyz/posts/leetcode_2155) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
