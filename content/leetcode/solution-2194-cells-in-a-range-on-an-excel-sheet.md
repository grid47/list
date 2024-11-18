
+++
authors = ["grid47"]
title = "Leetcode 2194: Cells in a Range on an Excel Sheet"
date = "2024-04-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2194: Cells in a Range on an Excel Sheet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jGLLCLtNDbQ"
youtube_upload_date="2022-03-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jGLLCLtNDbQ/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> cellsInRange(string s) {
    vector<string> res;
    for (char c = s[0]; c <= s[3]; ++c)
        for (char r = s[1]; r <= s[4]; ++r)
            res.push_back({c, r});
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2194.md" >}}
---
{{< youtube jGLLCLtNDbQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2196: Create Binary Tree From Descriptions](https://grid47.xyz/leetcode/solution-2196-create-binary-tree-from-descriptions/) |
| --- |
