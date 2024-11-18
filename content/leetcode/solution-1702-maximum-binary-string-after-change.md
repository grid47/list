
+++
authors = ["grid47"]
title = "Leetcode 1702: Maximum Binary String After Change"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1702: Maximum Binary String After Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FL972h3KqKA"
youtube_upload_date="2020-12-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FL972h3KqKA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-binary-string-after-change/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string maximumBinaryString(string binary) {
        int ones = 0, zeros = 0, n = binary.size();
        for (auto &c: binary) {
            if(c == '0')
            zeros++;
            else if (zeros == 0)
            ones++;
            c = '1';
        }
        if(ones < n)
        binary[zeros + ones -1] = '0';
        return binary;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1702.md" >}}
---
{{< youtube FL972h3KqKA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1704: Determine if String Halves Are Alike](https://grid47.xyz/leetcode/solution-1704-determine-if-string-halves-are-alike/) |
| --- |
