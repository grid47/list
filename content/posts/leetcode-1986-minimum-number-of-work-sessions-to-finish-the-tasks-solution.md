
+++
authors = ["grid47"]
title = "Leetcode 1986: Minimum Number of Work Sessions to Finish the Tasks"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1986: Minimum Number of Work Sessions to Finish the Tasks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> task;
    // map<int, map<int, int>> memo; map is costly
    int memo[1<<15][16];
    int minSessions(vector<int>& tasks, int sessionTime) {
        this->task = tasks;
        map<int, int> mp;
        int mask = 0;
        int tgt = ~(~0u << task.size());
        memset(memo, -1, sizeof(memo));
        // for(int i = 0; i < task.size(); i++)
        //     tgt |= 1 << i;
        return bt(tgt, 0, sessionTime, mask);
        
    }
    
    int bt(int tgt, int net, int st, int mask) {
        if(tgt == mask) {
            return 1;
        }
        if(memo[mask][net] != -1) return memo[mask][net];
        
        int ans = task.size();
        for(int i = 0; i < task.size(); i++) {
            if((mask >> i) & 1) continue;
            mask |= (1 << i);
            if(net + task[i] > st)
                ans = min(ans, 1 + bt(tgt, task[i], st, mask));
            else
                ans = min(ans, bt(tgt, net + task[i], st, mask));
            mask ^= (1 << i);
        }
        return memo[mask][net] = ans;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1986.md" >}}
---
{{< youtube 8TU3WceDlzI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1991: Find the Middle Index in Array](https://grid47.xyz/posts/leetcode-1991-find-the-middle-index-in-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}