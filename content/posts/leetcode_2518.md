
+++
authors = ["Crafted by Me"]
title = "Leetcode 2518: Number of Great Partitions"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2518: Number of Great Partitions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-great-partitions/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<unordered_map<int, int>> mem;
    vector<int> nums;
    vector<int> twos;    
    int mod = (int) 1e9 + 7;
    int n;
    
    int pos(int n) {
        if(n == 0) return 1;
        if(twos[n] != -1) return twos[n];
        long ans;
        if(n % 2) {
            ans = pos(n / 2);
            ans = (ans * ans * 2) % mod;
        } else {
            ans = pos(n / 2);
            ans = (ans * ans) % mod;            
        }
        return twos[n] = ans;
    }
    
    int dp(int idx, int l1, int l2) {
        
        if(idx == n) return (l1 <= 0 && l2 <= 0);
        
        if(l1 <= 0 && l2 <= 0) {
            return pos(n - idx) % mod;
        }
        int s = l1 * 10000 + l2;
        if(mem[idx].count(s)) return mem[idx][s];
        
        long ans = dp(idx + 1, l1 - nums[idx] <= 0? 0: l1 - nums[idx], l2) % mod;
        
        ans = (ans + dp(idx + 1, l1, l2 - nums[idx] <= 0? 0: l2 - nums[idx])) % mod;        
        
        return mem[idx][s] = ans;
    }
    
    int countPartitions(vector<int>& nums, int k) {
        sort(begin(nums), end(nums), greater<int>());
        n = nums.size();
        mem.resize(n);
        twos.resize(n + 1, -1);
        this->nums = nums;
        return dp(0, k, k);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2518.md" >}}
---
{{< youtube HwU0wcLoH-4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2520: Count the Digits That Divide a Number](https://grid47.xyz/posts/leetcode_2520) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
