
+++
authors = ["Crafted by Me"]
title = "Leetcode 2580: Count Ways to Group Overlapping Ranges"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2580: Count Ways to Group Overlapping Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countWays(vector<vector<int>>& range) {
        sort(range.begin(), range.end());
        int n = range.size();
        
        int mod = (int) 1e9 + 7;        
        int next = range[0][1];
        long cnt = 2;
        for(int i = 0; i < n; i++) {
            if(range[i][0] <= next) {
                next = max(next, range[i][1]);
                continue;
            }
            cnt = (cnt * 2) % mod;
            next = range[i][1];
        }

        return cnt;
    }
};
{{< /highlight >}}


---
{{< youtube 5-8-2mDdoGs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2581: Count Number of Possible Root Nodes](https://grid47.xyz/posts/leetcode_2581) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

