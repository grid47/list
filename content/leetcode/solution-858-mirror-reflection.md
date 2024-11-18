
+++
authors = ["grid47"]
title = "Leetcode 858: Mirror Reflection"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 858: Mirror Reflection in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fUa0LRtSlz0"
youtube_upload_date="2021-02-01"
youtube_thumbnail="https://i.ytimg.com/vi/fUa0LRtSlz0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/mirror-reflection/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while( p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p%2 + q%2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/858.md" >}}
---
{{< youtube fUa0LRtSlz0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #859: Buddy Strings](https://grid47.xyz/leetcode/solution-859-buddy-strings/) |
| --- |
