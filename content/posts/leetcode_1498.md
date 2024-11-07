
+++
authors = ["Crafted by Me"]
title = "Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int pow2(int idx) {
        if(idx == 0) return 1;
        long res;
        if(idx % 2) {
            res = pow2(idx / 2);
            res = (res * res * 2) % mod;
        }else {
            res = pow2(idx / 2);
            res = (res * res) % mod;            
        }
        return res;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        long res = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            if(nums[i] * 2 > target) break;
            
            int end = target - nums[i];
            auto it = upper_bound(nums.begin(), nums.end(), end);
            
            int idx = it - nums.begin();

            res = (res + pow2(idx - i - 1)) % mod;
            
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1498.md" >}}
---
{{< youtube WZhNEfbGYEo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1502: Can Make Arithmetic Progression From Sequence](https://grid47.xyz/posts/leetcode_1502) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
