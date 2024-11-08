
+++
authors = ["grid47"]
title = "Leetcode 1819: Number of Different Subsequences GCDs"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1819: Number of Different Subsequences GCDs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Counting","Number Theory"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-different-subsequences-gcds/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> fact(200001, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j * j <= nums[i]; j++) {
                if(nums[i] % j == 0) {
                    int f1 = j;
                    int f2 = nums[i] / j;
                    fact[f1] = __gcd(fact[f1], nums[i]);
                    fact[f2] = __gcd(fact[f2], nums[i]);                    
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i <= 200000; i++)
            if(fact[i] == i) res++;
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1819.md" >}}
---
{{< youtube nuWOwsepb00 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1822: Sign of the Product of an Array](https://grid47.xyz/posts/leetcode_1822) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
