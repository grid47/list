
+++
authors = ["grid47"]
title = "Leetcode 2561: Rearranging Fruits"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2561: Rearranging Fruits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearranging-fruits/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        map<int, int> c1;
        
        for(int x: b1) c1[x]++;
        for(int x: b2) c1[x]--;
        
        long long res = 0;
        
        vector<int> swaps;
        for(auto [k1, v1]: c1){
            if(v1 % 2) return -1;

            for(int i = 0; i < abs(v1) / 2; i++)
                swaps.push_back(k1);
        }
        
        int mn = c1.begin()->first;
        
        for(int i = 0; i < swaps.size() / 2; i++)
            res += min(swaps[i], mn * 2);

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2561.md" >}}
---
{{< youtube 59weIxEmESg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2562: Find the Array Concatenation Value](https://grid47.xyz/posts/leetcode-2562-find-the-array-concatenation-value-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
