
+++
authors = ["grid47"]
title = "Leetcode 1925: Count Square Sum Triples"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1925: Count Square Sum Triples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rWLEDxwWwiU"
youtube_upload_date="2021-07-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rWLEDxwWwiU/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-square-sum-triples/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTriples(int n) {
    vector<bool> squares(n * n + 1);
    for (int i = 1; i <= n; ++i)
        squares[i * i] = true;
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i; i * i + j * j <= n * n; ++j)
            res += squares[i * i + j * j] * 2;
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1925.md" >}}
---
{{< youtube rWLEDxwWwiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1926: Nearest Exit from Entrance in Maze](https://grid47.xyz/leetcode/solution-1926-nearest-exit-from-entrance-in-maze/) |
| --- |