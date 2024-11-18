
+++
authors = ["grid47"]
title = "Leetcode 2027: Minimum Moves to Convert String"
date = "2024-04-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2027: Minimum Moves to Convert String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hCuwkDkAXYM"
youtube_upload_date="2021-10-03"
youtube_thumbnail="https://i.ytimg.com/vi/hCuwkDkAXYM/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-convert-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), count = 0;
        while (i < n) {
            if (s[i] == 'O')
                i++;
            else
                count++, i += 3;
        }
        return count;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2027.md" >}}
---
{{< youtube hCuwkDkAXYM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2028: Find Missing Observations](https://grid47.xyz/leetcode/solution-2028-find-missing-observations/) |
| --- |
