
+++
authors = ["Crafted by Me"]
title = "Leetcode 1878: Get Biggest Three Rhombus Sums in a Grid"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1878: Get Biggest Three Rhombus Sums in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> s;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int sz = 0; i + sz < m && i - sz >= 0 && j + 2 * sz < n; sz++) {
                    
                    ll x = i, y = j, rsum = 0;
                    do rsum += grid[x++][y++]; while(x < i + sz);
                    if(sz > 0) {
                        
                        do rsum += grid[x--][y++]; while(y < j + 2 * sz);
                        do rsum += grid[x--][y--]; while(x > i - sz);
                        do rsum += grid[x++][y--]; while(x < i);
                        
                    }
                    s.insert(rsum);
                    if(s.size() > 3) {
                        s.erase(begin(s));}
                }
                }
            }
        return vector<int>(rbegin(s), rend(s));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1878.md" >}}
---
{{< youtube KAuzn8OcGXk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1879: Minimum XOR Sum of Two Arrays](https://grid47.xyz/posts/leetcode_1879) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

