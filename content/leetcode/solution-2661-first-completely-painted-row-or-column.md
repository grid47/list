
+++
authors = ["grid47"]
title = "Leetcode 2661: First Completely Painted Row or Column"
date = "2024-02-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2661: First Completely Painted Row or Column in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2661.md" >}}
---
{{< youtube -XgxrCAuu68 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2670: Find the Distinct Difference Array](https://grid47.xyz/leetcode/solution-2670-find-the-distinct-difference-array/) |
| --- |
