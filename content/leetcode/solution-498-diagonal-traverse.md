
+++
authors = ["grid47"]
title = "Leetcode 498: Diagonal Traverse"
date = "2024-09-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 498: Diagonal Traverse in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/498.webp"
youtube = "xio2uEQQPZQ"
youtube_upload_date="2020-04-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xio2uEQQPZQ/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/diagonal-traverse/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/498.webp" 
    alt="A matrix where elements are traversed diagonally, each element softly glowing as it is visited."
    caption="Solution to LeetCode 498: Diagonal Traverse Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        for(int s = 0; s <= m + n - 2; s++) {
            for(int x = 0; x <= s; x++) {
                int i = x;
                int j = s - i;
                if(s%2 == 0) swap(i, j);
                if(i >= m || j >= n) continue;
                res.push_back(mat[i][j]);
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/498.md" >}}
---
{{< youtube xio2uEQQPZQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #501: Find Mode in Binary Search Tree](https://grid47.xyz/leetcode/solution-501-find-mode-in-binary-search-tree/) |
| --- |