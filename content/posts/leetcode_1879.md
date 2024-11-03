
+++
authors = ["Crafted by Me"]
title = "Leetcode 1879: Minimum XOR Sum of Two Arrays"
date = "2019-09-11"
description = "In-depth solution and explanation for Leetcode 1879: Minimum XOR Sum of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> n1, n2;
    
    int memo[15][(1 << 14) - 1];
    
    int dp(int idx, int mask) {
        if(idx == n1.size()) return 0;
        
        if(memo[idx][mask] != -1) return memo[idx][mask];
        int ans = INT_MAX;
        
        for(int i = 0; i < n1.size(); i++) {
            if((mask & (1 << i)) == 0) {
                ans = min(ans, (n1[idx] ^ n2[i]) + dp(idx + 1, mask + (1 << i)));
            }
        }
        
        return memo[idx][mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        
        memset(memo, -1, sizeof(memo));
        
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1879.md" >}}
---
{{< youtube 7y5k-mlIpqg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1880: Check if Word Equals Summation of Two Words](https://grid47.xyz/posts/leetcode_1880) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

