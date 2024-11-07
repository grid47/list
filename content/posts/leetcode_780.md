
+++
authors = ["Crafted by Me"]
title = "Leetcode 780: Reaching Points"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 780: Reaching Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reaching-points/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    unordered_map<long, unordered_map<long, bool>> mp;

    bool pts(int sx, int sy, int tx, int ty) {

        if(sx == tx && sy == ty) return true;
        if(sx > tx || sy > ty) return false;

        if(mp.count(sx) && mp[sx].count(sy)) return mp[sx][sy];

        bool ans = pts(sx + sy, sy, tx, ty);
        if(ans) return true;
        ans = pts(sx, sx + sy, tx, ty);
        return mp[sx][sy] = ans;
    }

    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx < tx && sy < ty) {
            if(tx < ty) {
                ty %= tx;
            } else {
                tx %= ty;
            }
        }
        
        return  (sx == tx && sy <= ty && (ty - sy) % sx == 0) ||
                (sy == ty && sx <= tx && (tx - sx) % sy == 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/780.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #781: Rabbits in Forest](https://grid47.xyz/posts/leetcode_781) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
