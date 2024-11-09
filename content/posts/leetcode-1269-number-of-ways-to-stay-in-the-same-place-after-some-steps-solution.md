
+++
authors = ["grid47"]
title = "Leetcode 1269: Number of Ways to Stay in the Same Place After Some Steps"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1269: Number of Ways to Stay in the Same Place After Some Steps in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int n;
    vector<vector<int>> mem;
    
    int dp(int idx, int st) {
        // cout << idx << " " << st << "-";
        if(st == 0 && idx == 0) return 1;
        
        if(st == 0 || idx < 0 || idx >= n || st < idx) return 0;
        
        if(mem[idx][st] != -1) return mem[idx][st];

        long ans = (long)dp(idx, st - 1) % mod + (long)dp(idx + 1, st - 1)% mod + (long)dp(idx - 1, st - 1)% mod;
        
        return mem[idx][st] = ans % mod;
    }
    
    int numWays(int st, int n) {
        mem.resize(st/2 + 1, vector<int>(st + 1, -1));
        this->n = n;
        return dp(0, st);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1269.md" >}}
---
{{< youtube 8YBGXG-8sRI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1276: Number of Burgers with No Waste of Ingredients](https://grid47.xyz/posts/leetcode-1276-number-of-burgers-with-no-waste-of-ingredients-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
