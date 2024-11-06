
+++
authors = ["Crafted by Me"]
title = "Leetcode 1040: Moving Stones Until Consecutive II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1040: Moving Stones Until Consecutive II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/moving-stones-until-consecutive-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& pos) {
        sort(pos.begin(), pos.end());
        
        int low = INT_MAX;
        int j = 0, n = pos.size();
        for(int i = 0; i < n; i++) {
            while(pos[i] - pos[j] + 1 > n) j++;
            
            int cnt = i - j + 1;
            
            if(cnt == n - 1 && pos[i] - pos[j] + 1 == n - 1)
                low = min(low, 2);
            else low = min(low, n - cnt);
        }
        return vector<int>{low, max(pos[n - 1] - pos[1] + 1 - (n - 1), pos[n - 2] - pos[0] + 1 - (n - 1))};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1040.md" >}}
---
{{< youtube 4Xhq2NDbA-I >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1041: Robot Bounded In Circle](https://grid47.xyz/posts/leetcode_1041) |
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
