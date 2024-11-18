
+++
authors = ["grid47"]
title = "Leetcode 1227: Airplane Seat Assignment Probability"
date = "2024-07-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1227: Airplane Seat Assignment Probability in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Brainteaser","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pHgWf79hNoY"
youtube_upload_date="2024-02-05"
youtube_thumbnail="https://i.ytimg.com/vi/pHgWf79hNoY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/airplane-seat-assignment-probability/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1;
        return 1/2.0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1227.md" >}}
---
{{< youtube pHgWf79hNoY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1232: Check If It Is a Straight Line](https://grid47.xyz/leetcode/solution-1232-check-if-it-is-a-straight-line/) |
| --- |
