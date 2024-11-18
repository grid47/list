
+++
authors = ["grid47"]
title = "Leetcode 2536: Increment Submatrices by One"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2536: Increment Submatrices by One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "K4SJb0I-_hw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/increment-submatrices-by-one/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        for(int i = 0; i < q.size(); i++) {
            auto it = q[i];
            for(int j = q[i][0]; j <= q[i][2]; j++) {
                ans[j][q[i][1]] += 1;
                if(q[i][3] < n - 1)
                    ans[j][q[i][3] + 1] -=1;
            }
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            ans[i][j] += ans[i][j - 1];
        
        return ans;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2536.md" >}}
---
{{< youtube K4SJb0I-_hw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2537: Count the Number of Good Subarrays](https://grid47.xyz/leetcode/solution-2537-count-the-number-of-good-subarrays/) |
| --- |
