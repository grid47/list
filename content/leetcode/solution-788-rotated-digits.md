
+++
authors = ["grid47"]
title = "Leetcode 788: Rotated Digits"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 788: Rotated Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/788.webp"
youtube = "QOQL3S2BHPs"
youtube_upload_date="2020-02-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QOQL3S2BHPs/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/rotated-digits/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/788.webp" 
    alt="A set of digits where the rotated digits are found, glowing softly as the valid rotations are made."
    caption="Solution to LeetCode 788: Rotated Digits Problem"
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
    int rotatedDigits(int n) {
        int f[] = {1,1,2,0,0,2,2,0,1,2};
        int res = 0;
        for(int i = 0; i <= n; i++) {
            int p = i;
            int s = 1;
            while(p) {
                s *= f[p%10];
                p /= 10;
            }
            if (s >= 2) res +=1;
        }        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/788.md" >}}
---
{{< youtube QOQL3S2BHPs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #789: Escape The Ghosts](https://grid47.xyz/leetcode/solution-789-escape-the-ghosts/) |
| --- |