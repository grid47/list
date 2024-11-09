
+++
authors = ["grid47"]
title = "Leetcode 1931: Painting a Grid With Three Different Colors"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1931: Painting a Grid With Three Different Colors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int memo[1001][1024] = {};
    int mod = (int) 1e9 + 7;
    int colorTheGrid(int m, int n, int i = 0, int j = 0, int cur = 0, int prv = 0) {
        if(i == m) return colorTheGrid(m, n, 0, j + 1, 0, cur);
                
        if(j == n) return 1;
        
        if(i == 0 && memo[j][prv]) return memo[j][prv];        
        
        int up = i == 0? 0: (cur >> (i - 1) * 2) & 3;
        int lft = (prv >> (i) * 2) & 3;
        
        int ans = 0;
        for(int k = 1; k < 4; k++) {
            if(up != k && lft != k)
                ans = (ans + colorTheGrid(m, n, i + 1, j, cur + (k << i * 2), prv)) % mod;
        }
        if(i == 0) memo[j][prv] = ans;
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1931.md" >}}
---
{{< youtube 9ccqkYrH3JM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1935: Maximum Number of Words You Can Type](https://grid47.xyz/posts/leetcode-1931-painting-a-grid-with-three-different-colors-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
