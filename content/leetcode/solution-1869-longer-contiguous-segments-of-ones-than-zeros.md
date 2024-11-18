
+++
authors = ["grid47"]
title = "Leetcode 1869: Longer Contiguous Segments of Ones than Zeros"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1869: Longer Contiguous Segments of Ones than Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "K0WT66cPNmo"
youtube_upload_date="2021-05-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/K0WT66cPNmo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkZeroOnes(string s) {
        int z = 0, o = 0, gz = 0, oz = 0, res = 1;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') z++;
            else z = 0;
            if(s[i] == '1') o++;
            else o = 0;
            gz = max(gz, z);
            oz = max(oz, o);
        }
        return oz > gz;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1869.md" >}}
---
{{< youtube K0WT66cPNmo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1870: Minimum Speed to Arrive on Time](https://grid47.xyz/leetcode/solution-1870-minimum-speed-to-arrive-on-time/) |
| --- |
