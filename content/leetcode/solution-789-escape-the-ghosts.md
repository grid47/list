
+++
authors = ["grid47"]
title = "Leetcode 789: Escape The Ghosts"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 789: Escape The Ghosts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/789.webp"
youtube = "fCx9Fb_ghaA"
youtube_upload_date="2019-04-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/fCx9Fb_ghaA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/escape-the-ghosts/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/789.webp" 
    alt="A set of ghosts where escape routes are traced, with each route softly glowing as it’s followed."
    caption="Solution to LeetCode 789: Escape The Ghosts Problem"
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
    bool escapeGhosts(vector<vector<int>>& gs, vector<int>& t) {
        int d = abs(t[0]) + abs(t[1]);
        for(auto it: gs)
        if(d >= abs(it[0] - t[0]) + abs(it[1] - t[1]))
        return false;
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/789.md" >}}
---
{{< youtube fCx9Fb_ghaA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #790: Domino and Tromino Tiling](https://grid47.xyz/leetcode/solution-790-domino-and-tromino-tiling/) |
| --- |
