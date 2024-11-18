
+++
authors = ["grid47"]
title = "Leetcode 593: Valid Square"
date = "2024-09-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 593: Valid Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/593.webp"
youtube = "5ErP0_vpzvI"
youtube_upload_date="2020-07-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/5ErP0_vpzvI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/valid-square/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/593.webp" 
    alt="A square being validated, with each corner softly glowing as the square is checked for correctness."
    caption="Solution to LeetCode 593: Valid Square Problem"
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
    int d(vector<int> p, vector<int> q) {
        return (p[0] - q[0])*(p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s({d(p1, p2), d(p2, p3), d(p3, p4), d(p4, p1), d(p1, p3), d(p2, p4)});
        return !s.count(0) && s.size() == 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/593.md" >}}
---
{{< youtube 5ErP0_vpzvI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #606: Construct String from Binary Tree](https://grid47.xyz/leetcode/solution-606-construct-string-from-binary-tree/) |
| --- |
