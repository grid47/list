
+++
authors = ["grid47"]
title = "Leetcode 1314: Matrix Block Sum"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1314: Matrix Block Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jor18pkf9EE"
youtube_upload_date="2020-11-07"
youtube_thumbnail="https://i.ytimg.com/vi/jor18pkf9EE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/matrix-block-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i < m + 1; i++)
        for(int j = 1; j < n + 1; j++)
        sum[i][j] = mat[i - 1][j - 1] + (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
        
        vector<vector<int>> res(m, vector<int>(n));

        for(int i = 1; i < m + 1; i++)
        for(int j = 1; j < n + 1; j++) {

            int r1 = min(i + k, m);
            int c1 = min(j + k, n);
            int r2 = max(i - k, 1);
            int c2 = max(j - k, 1);

            res[i - 1][j - 1] = sum[r1][c1] - sum[r1][c2 - 1] - sum[r2 - 1][c1] + sum[r2 - 1][c2 - 1];

        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1314.md" >}}
---
{{< youtube jor18pkf9EE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1315: Sum of Nodes with Even-Valued Grandparent](https://grid47.xyz/leetcode/solution-1315-sum-of-nodes-with-even-valued-grandparent/) |
| --- |
