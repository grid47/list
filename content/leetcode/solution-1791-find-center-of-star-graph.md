
+++
authors = ["grid47"]
title = "Leetcode 1791: Find Center of Star Graph"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1791: Find Center of Star Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jBD2_Eh4SlU"
youtube_upload_date="2021-03-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jBD2_Eh4SlU/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-center-of-star-graph/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1791.md" >}}
---
{{< youtube jBD2_Eh4SlU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1792: Maximum Average Pass Ratio](https://grid47.xyz/leetcode/solution-1792-maximum-average-pass-ratio/) |
| --- |
