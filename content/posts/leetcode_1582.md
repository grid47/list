
+++
authors = ["Crafted by Me"]
title = "Leetcode 1582: Special Positions in a Binary Matrix"
date = "2019-07-04"
description = "Solution to Leetcode 1582"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        int res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) row[i]++, col[j]++;
        }

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) {
                res++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

