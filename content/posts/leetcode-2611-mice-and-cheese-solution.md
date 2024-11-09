
+++
authors = ["grid47"]
title = "Leetcode 2611: Mice and Cheese"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2611: Mice and Cheese in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/mice-and-cheese/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        
        int n = r1.size();

        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            ans.push_back({r1[i] - r2[i], r1[i], r2[i]});
        }
        sort(ans.begin(), ans.end(), greater<vector<int>>());
        
        int res = 0, i = 0;
        while(k--) {
            res += ans[i++][1];
        }
        while(i < n) res += ans[i++][2];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2611.md" >}}
---
{{< youtube S_pCzVdQX9U >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2614: Prime In Diagonal](https://grid47.xyz/posts/leetcode-2614-prime-in-diagonal-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
