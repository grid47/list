
+++
authors = ["grid47"]
title = "Leetcode 2087: Minimum Cost Homecoming of a Robot in a Grid"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2087: Minimum Cost Homecoming of a Robot in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> row, col;
    vector<vector<long>> vis, vs;
    int m, n;
    
    int minCost(vector<int>& start, vector<int>& home, vector<int>& row, vector<int>& col) {
        m = row.size();
        n = col.size();
        int ans = 0;
        int i = start[0], x = home[0];
        int j = start[1], y = home[1];
        while(i != x) {
            i += (x - i) / abs(x - i);
            ans += row[i];
        }
        
        while(j != y) {
            j += (y - j) / abs(y - j);
            ans += col[j];
        }        
        return ans;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2087.md" >}}
---
{{< youtube -ect7lESvLg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2090: K Radius Subarray Averages](https://grid47.xyz/posts/leetcode-2087-minimum-cost-homecoming-of-a-robot-in-a-grid-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
