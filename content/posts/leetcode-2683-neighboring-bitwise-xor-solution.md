
+++
authors = ["grid47"]
title = "Leetcode 2683: Neighboring Bitwise XOR"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2683: Neighboring Bitwise XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/neighboring-bitwise-xor/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool doesValidArrayExist(vector<int>& nums) {
        int n = nums.size();
        // same 0 0
        
        int fst = 0, scd = 1;
        for(int i = 0; i < n; i++) {
            fst ^= nums[i];
            scd ^= nums[i];
        }
        if(fst == 0 || scd == 1) return true;
        return false;
        // same 1 1
        // different 1 0
        // different 0 1        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2683.md" >}}
---
{{< youtube DDQR_mDTTFI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2684: Maximum Number of Moves in a Grid](https://grid47.xyz/posts/leetcode-2683-neighboring-bitwise-xor-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
