
+++
authors = ["grid47"]
title = "Leetcode 2425: Bitwise XOR of All Pairings"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2425: Bitwise XOR of All Pairings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        int xr1 = nums1[0], xr2 = nums2[0];
        
        for(int i = 1; i < m; i++)
            xr1 ^= nums1[i];
        
        for(int i = 1; i < n; i++)
            xr2 ^= nums2[i];

        if((n % 2) == 0) {
            if((m % 2) == 0) {
                return 0;
            } else {
                return xr2;
            }
        } else {
            if((m % 2) == 0) {
                return xr1;
            } else {
                return xr1 ^ xr2;
            }            
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2425.md" >}}
---
{{< youtube mFFtmUdq2jI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2427: Number of Common Factors](https://grid47.xyz/posts/leetcode-2427-number-of-common-factors-solution/) |
| --- |
