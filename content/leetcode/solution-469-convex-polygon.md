
+++
authors = ["grid47"]
title = "Leetcode 469: Convex Polygon"
date = "2024-09-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 469: Convex Polygon in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/469.webp"
youtube = "5xvMeI0R6uY"
youtube_upload_date="2024-02-03"
youtube_thumbnail="https://i.ytimg.com/vi/5xvMeI0R6uY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/convex-polygon/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/469.webp" 
    alt="A series of points forming a convex polygon, with the final shape softly glowing once completed."
    caption="Solution to LeetCode 469: Convex Polygon Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int result = 40;
        while(result >= 40) { result = (7 * (rand7() - 1)) + (rand7() -1); }
        return result % 10 + 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/469.md" >}}
---
{{< youtube 5xvMeI0R6uY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #474: Ones and Zeroes](https://grid47.xyz/leetcode/solution-474-ones-and-zeroes/) |
| --- |