
+++
authors = ["grid47"]
title = "Leetcode 2264: Largest 3-Same-Digit Number in String"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2264: Largest 3-Same-Digit Number in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vcrOpJQHsSE"
youtube_upload_date="2023-12-04"
youtube_thumbnail="https://i.ytimg.com/vi/vcrOpJQHsSE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestGoodInteger(string num) {
        char res = 0;
    for(int i = 2; i < num.size(); ++i)
        if (num[i] == num[i - 1] && num[i] == num[i - 2])
            res = max(res, num[i]);
    return res == 0 ? "" : string(3, res);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2264.md" >}}
---
{{< youtube vcrOpJQHsSE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2265: Count Nodes Equal to Average of Subtree](https://grid47.xyz/leetcode/solution-2265-count-nodes-equal-to-average-of-subtree/) |
| --- |