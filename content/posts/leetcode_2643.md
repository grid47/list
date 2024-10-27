
+++
authors = ["Yasir"]
title = "Leetcode 2643: Row With Maximum Ones"
date = "2017-08-03"
description = "Solution to Leetcode 2643"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/row-with-maximum-ones/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int mx = 0, idx = 0;
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++)
                if(mat[i][j]) cnt++;
            if(cnt > mx) {
                idx = i;
                mx = cnt;
            }
        }
        return vector<int>{idx, mx};
    }
};
{{< /highlight >}}

