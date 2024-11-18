
+++
authors = ["grid47"]
title = "Leetcode 2643: Row With Maximum Ones"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2643: Row With Maximum Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "yieYsDt7yVM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/row-with-maximum-ones/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2643.md" >}}
---
{{< youtube yieYsDt7yVM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2644: Find the Maximum Divisibility Score](https://grid47.xyz/leetcode/solution-2644-find-the-maximum-divisibility-score/) |
| --- |
