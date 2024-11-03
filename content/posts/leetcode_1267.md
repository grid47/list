
+++
authors = ["Crafted by Me"]
title = "Leetcode 1267: Count Servers that Communicate"
date = "2021-05-15"
description = "In-depth solution and explanation for Leetcode 1267: Count Servers that Communicate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-servers-that-communicate/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((grid[i][j] == 1) && ((row[i] > 1) || (col[j] > 1))) {
                    res++;
                }
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1267.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1268: Search Suggestions System](https://grid47.xyz/posts/leetcode_1268) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

