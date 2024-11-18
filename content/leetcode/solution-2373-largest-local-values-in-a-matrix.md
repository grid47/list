
+++
authors = ["grid47"]
title = "Leetcode 2373: Largest Local Values in a Matrix"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2373: Largest Local Values in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wdTRu9sarFA"
youtube_upload_date="2024-05-12"
youtube_thumbnail="https://i.ytimg.com/vi/wdTRu9sarFA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/largest-local-values-in-a-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
vector<vector<int>> largestLocal(vector<vector<int>>& g) {
    int n = g.size();
    vector<vector<int>> res(n - 2, vector<int>(n - 2));
    for (int i = 0; i < n - 2; ++i)
        for (int j = 0; j < n - 2; ++j)
            for (int ii = i; ii < i + 3; ++ii)
                for (int jj = j; jj < j + 3; ++jj)
                    res[i][j] = max(res[i][j], g[ii][jj]);
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2373.md" >}}
---
{{< youtube wdTRu9sarFA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2374: Node With Highest Edge Score](https://grid47.xyz/leetcode/solution-2374-node-with-highest-edge-score/) |
| --- |
