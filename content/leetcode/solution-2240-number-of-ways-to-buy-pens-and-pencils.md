
+++
authors = ["grid47"]
title = "Leetcode 2240: Number of Ways to Buy Pens and Pencils"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2240: Number of Ways to Buy Pens and Pencils in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WzmIQmBNa0A"
youtube_upload_date="2022-04-16"
youtube_thumbnail="https://i.ytimg.com/vi/WzmIQmBNa0A/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long cnt = 0;
        int sum = total;
        while(sum >= 0 || sum/cost2 > 0) {
            cnt+= (sum/cost2 + 1);
            sum -= cost1;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2240.md" >}}
---
{{< youtube WzmIQmBNa0A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2241: Design an ATM Machine](https://grid47.xyz/leetcode/solution-2241-design-an-atm-machine/) |
| --- |
