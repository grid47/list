
+++
authors = ["grid47"]
title = "Leetcode 1694: Reformat Phone Number"
date = "2024-05-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1694: Reformat Phone Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "U8EwUjwKYFg"
youtube_upload_date="2020-12-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/U8EwUjwKYFg/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/reformat-phone-number/description/)

---
**Code:**

{{< highlight cpp >}}
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reformatNumber(string s) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) s[j++] = s[i];
        }
        s.resize(j);
        string ans;
        for (int i = 0, r = s.size(); i < s.size(); ) {
            for (int d = r == 2 || r == 4 ? 2 : 3; d > 0; --d, --r) {
                ans += s[i++];
            }
            if (r) ans += '-';
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1694.md" >}}
---
{{< youtube U8EwUjwKYFg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1695: Maximum Erasure Value](https://grid47.xyz/leetcode/solution-1695-maximum-erasure-value/) |
| --- |