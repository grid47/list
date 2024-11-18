
+++
authors = ["grid47"]
title = "Leetcode 1572: Matrix Diagonal Sum"
date = "2024-06-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1572: Matrix Diagonal Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "5TLlr3y3Iww"
youtube_upload_date="2023-05-09"
youtube_thumbnail="https://i.ytimg.com/vi/5TLlr3y3Iww/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/matrix-diagonal-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for(int i = 0; i < n; i++)
            sum += mat[i][i] + mat[n - 1 - i][i];
        if(n % 2) sum -= mat[n/2][n/2];
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1572.md" >}}
---
{{< youtube 5TLlr3y3Iww >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1573: Number of Ways to Split a String](https://grid47.xyz/leetcode/solution-1573-number-of-ways-to-split-a-string/) |
| --- |
