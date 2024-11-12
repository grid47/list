
+++
authors = ["grid47"]
title = "Leetcode 2683: Neighboring Bitwise XOR"
date = "2024-02-12"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2684: Maximum Number of Moves in a Grid](https://grid47.xyz/posts/leetcode-2684-maximum-number-of-moves-in-a-grid-solution/) |
| --- |
