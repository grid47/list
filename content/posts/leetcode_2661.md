
+++
authors = ["Crafted by Me"]
title = "Leetcode 2661: First Completely Painted Row or Column"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2661: First Completely Painted Row or Column in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-completely-painted-row-or-column/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, long> r, c, mtx;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            mtx[mat[i][j]] = (long) i * 100000 + j;
        }
        for(int i = 0; i < arr.size(); i++) {
            long k = mtx[arr[i]];
            long x = k / 100000;
            long y = k % 100000;
            r[x]++;

            if(r[x] == n) return i;
            c[y]++;
            if(c[y] == m) return i;
            // cout << x << " "<< y << " " << r[x] << " " << c[y] << " " << m << " " << n << "\n";            
            // if(i == 2) break;
        }
        return -1;
    }
};
{{< /highlight >}}


---
{{< youtube -XgxrCAuu68 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2662: Minimum Cost of a Path With Special Roads](https://grid47.xyz/posts/leetcode_2662) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

