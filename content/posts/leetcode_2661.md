
+++
authors = ["Yasir"]
title = "Leetcode 2661: First Completely Painted Row or Column"
date = "2017-07-16"
description = "Solution to Leetcode 2661"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-completely-painted-row-or-column/description/)

---

**Code:**

{{< highlight html >}}
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

