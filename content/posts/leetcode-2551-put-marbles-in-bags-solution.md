
+++
authors = ["grid47"]
title = "Leetcode 2551: Put Marbles in Bags"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2551: Put Marbles in Bags in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/put-marbles-in-bags/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    long long putMarbles(vector<int>& weights, int k) {
        
        vector<int> diff;
        int n = weights.size();
        for(int i = 1; i < n; i++)
            diff.push_back(weights[i] + weights[i - 1]);
        
        sort(diff.begin(), diff.end());
        
        long long ma = 0, mi = 0;
        for(int i = 0; i + 1 < k && i < diff.size(); i++) {
            mi += diff[i];
            ma += diff[n - 2 - i];
        }
        
        return ma - mi;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2551.md" >}}
---
{{< youtube xkkPiOLS1Oc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2553: Separate the Digits in an Array](https://grid47.xyz/posts/leetcode-2551-put-marbles-in-bags-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
