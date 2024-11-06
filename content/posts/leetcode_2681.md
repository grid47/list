
+++
authors = ["Crafted by Me"]
title = "Leetcode 2681: Power of Heroes"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2681: Power of Heroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Sorting","Prefix Sum"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/power-of-heroes/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
                
        sort(nums.begin(), nums.end());
        
        
        int n = nums.size();
        long long res = 0, sum = 0, mod = (int) 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            res = (res + (sum + nums[i]) * nums[i] % mod * nums[i]) % mod;
            sum = (sum * 2 + nums[i]) % mod;
        }
        
        return res % mod;
        
    }
};
{{< /highlight >}}


---
{{< youtube ijJ025IUyN4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2682: Find the Losers of the Circular Game](https://grid47.xyz/posts/leetcode_2682) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

