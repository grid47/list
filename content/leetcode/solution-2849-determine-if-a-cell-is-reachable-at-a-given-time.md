
+++
authors = ["grid47"]
title = "Leetcode 2849: Determine if a Cell Is Reachable at a Given Time"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2849: Determine if a Cell Is Reachable at a Given Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "r4MaK8AhoLI"
youtube_upload_date="2023-09-10"
youtube_thumbnail="https://i.ytimg.com/vi/r4MaK8AhoLI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        int mn = min(abs(fy - sy), abs(fx - sx));
        int asdf = (abs(fy - sy) - mn)+ (abs(fx - sx) - mn) + mn;
        if(abs(fy - sy) == 0 && abs(fx - sx) == 0 && t == 1) return false;
        return asdf <= t;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2849.md" >}}
---
{{< youtube r4MaK8AhoLI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2850: Minimum Moves to Spread Stones Over Grid](https://grid47.xyz/leetcode/solution-2850-minimum-moves-to-spread-stones-over-grid/) |
| --- |