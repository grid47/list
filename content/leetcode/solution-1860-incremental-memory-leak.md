
+++
authors = ["grid47"]
title = "Leetcode 1860: Incremental Memory Leak"
date = "2024-05-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1860: Incremental Memory Leak in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BoIe1HDe83c"
youtube_upload_date="2021-05-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BoIe1HDe83c/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/incremental-memory-leak/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> memLeak(int mem1, int mem2) {
        int i = 1;
        while(i <= mem1 || i <= mem2) {
            if(mem1 >= mem2) {
                mem1 -= i;
            } else mem2 -= i;
            i++;
        }
        return vector<int>{i, mem1, mem2};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1860.md" >}}
---
{{< youtube BoIe1HDe83c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1861: Rotating the Box](https://grid47.xyz/leetcode/solution-1861-rotating-the-box/) |
| --- |