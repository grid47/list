
+++
authors = ["grid47"]
title = "Leetcode 3178: Find the Child Who Has the Ball After K Seconds"
date = "2023-12-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3178: Find the Child Who Has the Ball After K Seconds in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "JX-J9LZxqvk"
youtube_upload_date="2024-06-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/JX-J9LZxqvk/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfChild(int n, int k) {
        int up = false, idx = 0;
        for(int i = 0; i < k; i++) {

            if (idx == n - 1 || idx == 0) up = !up;

            if (up) idx++;
            else    idx--;

        }
        return idx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3178.md" >}}
---
{{< youtube JX-J9LZxqvk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3179: Find the N-th Value After K Seconds](https://grid47.xyz/leetcode/solution-3179-find-the-n-th-value-after-k-seconds/) |
| --- |
