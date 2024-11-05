
+++
authors = ["Crafted by Me"]
title = "Leetcode 2639: Find the Width of Columns of a Grid"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2639: Find the Width of Columns of a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int get(int num) {
        if(num == 0) return 1;
        int len = num < 0? 1: 0;
        num = abs(num);
        while(num > 0) {
            len++;
            num/=10;
        }
        return len;
    }
    
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int len = 0;
            for(int j = 0; j < m; j++) {
                len = max(len, get(grid[j][i]));
            }
            ans[i] = len;
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube RSRjK563HVY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2640: Find the Score of All Prefixes of an Array](https://grid47.xyz/posts/leetcode_2640) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

