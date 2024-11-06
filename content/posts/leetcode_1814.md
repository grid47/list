
+++
authors = ["Crafted by Me"]
title = "Leetcode 1814: Count Nice Pairs in an Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1814: Count Nice Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-nice-pairs-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int, long> mp;
        for(auto &n: nums) mp[n - rev(n)]++;
        
        int mod = 1000000007;
        long count = 0;
        
        for(auto &it: mp) 
        count = (count + (it.second * (it.second - 1))/ 2) % mod;
        
        return count;
    }

    int rev(int x) {
        int revNum = 0;
        while(x) revNum = revNum * 10 + (x%10), x /= 10;
        return revNum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1814.md" >}}
---
{{< youtube qUNprFiUKyw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1815: Maximum Number of Groups Getting Fresh Donuts](https://grid47.xyz/posts/leetcode_1815) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
