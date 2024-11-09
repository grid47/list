
+++
authors = ["grid47"]
title = "Leetcode 475: Heaters"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 475: Heaters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/heaters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findRadius(vector<int>& home, vector<int>& warm) {
        sort(home.begin(), home.end());
        sort(warm.begin(), warm.end());
        int m = home.size(), n = warm.size();
        
        vector<int> res(m, INT_MAX);
        
        for(int h = 0, w = 0; h < m && w < n; ) {
            if (home[h] <= warm[w]) {
                res[h] = warm[w] - home[h];
                h++;
            } else w++;
        }
        
        for(int h = m - 1, w = n - 1; h >= 0 && w >= 0; ) {
            if (home[h] >= warm[w]) {
                res[h] = min(res[h], home[h] - warm[w]);
                h--;
            } else w--;
        }
        
        return *max_element(res.begin(), res.end());
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/475.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #477: Total Hamming Distance](https://grid47.xyz/posts/leetcode-477-total-hamming-distance-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
