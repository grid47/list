
+++
authors = ["grid47"]
title = "Leetcode 1812: Determine Color of a Chessboard Square"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1812: Determine Color of a Chessboard Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool squareIsWhite(string cord) {
        int x = cord[0] - 'a' + 1;
        x += cord[1] - '0';
        return x % 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1812.md" >}}
---
{{< youtube 7qcZLTyTl5s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1813: Sentence Similarity III](https://grid47.xyz/leetcode/solution-1813-sentence-similarity-iii/) |
| --- |
