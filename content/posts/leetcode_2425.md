
+++
authors = ["Crafted by Me"]
title = "Leetcode 2425: Bitwise XOR of All Pairings"
date = "2018-03-14"
description = "In-depth solution and explanation for Leetcode 2425: Bitwise XOR of All Pairings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2426: Number of Pairs Satisfying Inequality](https://grid47.xyz/posts/leetcode_2426) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

