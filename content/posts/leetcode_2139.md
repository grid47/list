
+++
authors = ["Crafted by Me"]
title = "Leetcode 2139: Minimum Moves to Reach Target Score"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2139: Minimum Moves to Reach Target Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-reach-target-score/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<int, map<int, int>> mp;
    int dp(int cur, int end, int dops) {
        if(cur == end) return 0;
        if(cur > end) return INT_MAX - 1;
        
        if(mp.count(cur) && mp[cur].count(dops)) return mp[cur][dops];
        
        int ans = 1 + dp(cur + 1, end, dops);
        if(dops > 0)
        ans = min(ans, 1 + dp(cur * 2, end, dops - 1));
        
        return mp[cur][dops] = ans;
    }
    
    int minMoves(int end, int dops) {
        
        int cnt = 0;
        
        while(end > 1) {
            if(end % 2) end -= 1;
            else if(dops > 0) {
                end /= 2;
                dops--;
            } else {
                cnt += (end -1);
                break;                
            }
            cnt++;
        }
        return cnt;
        
        // return dp(1, end, dops);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2139.md" >}}
---
{{< youtube y3r6o712auw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2140: Solving Questions With Brainpower](https://grid47.xyz/posts/leetcode_2140) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
