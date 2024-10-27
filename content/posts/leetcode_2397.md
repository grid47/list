
+++
authors = ["Yasir"]
title = "Leetcode 2397: Maximum Rows Covered by Columns"
date = "2018-04-06"
description = "Solution to Leetcode 2397"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-rows-covered-by-columns/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumRows(vector<vector<int>>& mtx, int sel) {
        int m = mtx.size(), n = mtx[0].size();
        
        int ans = 0;
        for(int msk = 0; msk < (1 << n); msk++) {
            if(__builtin_popcount(msk) != sel) continue;
            int res = 0;
            for(int i = 0; i < m; i++) {
                bool take = true;
                for(int j = 0; j < n; j++)
                    if(mtx[i][j] && (((msk >> j) & 1) == 0)) {
                        take = false;
                        break;
                    }
                if(take) res++;
            }
            ans = max(ans, res);
        }
        
        
        return ans;
    }

};
{{< /highlight >}}

