
+++
authors = ["Crafted by Me"]
title = "Leetcode 2425: Bitwise XOR of All Pairings"
date = "2018-03-14"
description = "Solution to Leetcode 2425"
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

