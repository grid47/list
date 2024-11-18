
+++
authors = ["grid47"]
title = "Leetcode 3168: Minimum Number of Chairs in a Waiting Room"
date = "2023-12-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3168: Minimum Number of Chairs in a Waiting Room in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "-VAEXKFWfXo"
youtube_upload_date="2024-06-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-VAEXKFWfXo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumChairs(string s) {
        int mx = 0, cnt = 0;
        for(char x: s) {
            cnt += (x == 'E'? 1: -1);
            mx = max(mx, cnt);
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3168.md" >}}
---
{{< youtube -VAEXKFWfXo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3169: Count Days Without Meetings](https://grid47.xyz/leetcode/solution-3169-count-days-without-meetings/) |
| --- |
