
+++
authors = ["Crafted by Me"]
title = "Leetcode 2572: Count the Number of Square-Free Subsets"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2572: Count the Number of Square-Free Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7, n;
    vector<int> nums, prime;
    int memo[1001][1 << 11];
    
    int getMask(int num) {
        int mask = 0;
        for(int i= 0; i < prime.size(); i++) {
            int cnt = 0;
            while(num % prime[i] == 0) {
                cnt++;
                num /= prime[i];
            }
            if(cnt > 1) return -1;
            if(cnt == 1) {
                mask |= (1 << (i + 1));                
            }
        }
        return mask;
    }    

    int dp(int idx, int mask) {
        if(idx == n) return 1;

        if(memo[idx][mask] != -1) return memo[idx][mask];        
        int ans = dp(idx + 1, mask);

        int nmask = getMask(nums[idx]);
        if((nmask != -1) && ((nmask & mask) == 0)) {
            ans = (ans + dp(idx + 1, nmask | mask)) % mod;
        }
        return memo[idx][mask] = ans;
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        memset(memo, -1, sizeof memo);
        return (dp(0, 0) - 1 + mod) % mod;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2572.md" >}}
---
{{< youtube rT4w58kX818 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2574: Left and Right Sum Differences](https://grid47.xyz/posts/leetcode_2574) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
