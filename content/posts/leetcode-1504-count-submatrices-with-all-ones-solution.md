
+++
authors = ["grid47"]
title = "Leetcode 1504: Count Submatrices With All Ones"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1504: Count Submatrices With All Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Matrix","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-submatrices-with-all-ones/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cnt += helper(mat, i, j);        
        return cnt;
    }

    int helper(vector<vector<int>>& mat, int a, int b) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0, bnd = n;
        for(int i = a; i < m; i++)
        for(int j = b; j < bnd; j++) {
            if(mat[i][j]) cnt +=1;
            else bnd = j;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1504.md" >}}
---
{{< youtube 8miqwSN3EFo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1508: Range Sum of Sorted Subarray Sums](https://grid47.xyz/posts/leetcode-1508-range-sum-of-sorted-subarray-sums-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
