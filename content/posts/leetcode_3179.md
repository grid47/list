
+++
authors = ["Crafted by Me"]
title = "Leetcode 3179: Find the N-th Value After K Seconds"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3179: Find the N-th Value After K Seconds in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation","Combinatorics","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
        vector<vector<long>> mtx(k + 1, vector<long>(n, 1));
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j < n; j++) {
                mtx[i][j] = (mtx[i - 1][j] + mtx[i][j - 1]) % mod;   
            }
        }
        return mtx[k][n - 1];
    }
};
{{< /highlight >}}


---
{{< youtube 4sO18TX7Qzw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3180: Maximum Total Reward Using Operations I](https://grid47.xyz/posts/leetcode_3180) |
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
