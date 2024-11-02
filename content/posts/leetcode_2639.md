
+++
authors = ["Crafted by Me"]
title = "Leetcode 2639: Find the Width of Columns of a Grid"
date = "2017-08-12"
description = "Solution to Leetcode 2639"
tags = [
    
]
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

