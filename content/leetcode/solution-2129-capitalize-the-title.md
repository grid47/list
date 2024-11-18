
+++
authors = ["grid47"]
title = "Leetcode 2129: Capitalize the Title"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2129: Capitalize the Title in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "LDlUaEaunY0"
youtube_upload_date="2022-01-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/LDlUaEaunY0/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/capitalize-the-title/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string capitalizeTitle(string s) {
        for (int i = 0, j = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (i - j > 2)
                    s[j] = toupper(s[j]);
                j = i + 1;
            }
            else
                s[i] = tolower(s[i]);
        }
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2129.md" >}}
---
{{< youtube LDlUaEaunY0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2130: Maximum Twin Sum of a Linked List](https://grid47.xyz/leetcode/solution-2130-maximum-twin-sum-of-a-linked-list/) |
| --- |
