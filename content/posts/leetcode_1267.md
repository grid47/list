
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1267: Count Servers that Communicate"
date = "2021-05-12"
description = "Solution to Leetcode 1267"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

