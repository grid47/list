
+++
authors = ["grid47"]
title = "Leetcode 1016: Binary String With Substrings Representing 1 To N"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1016: Binary String With Substrings Representing 1 To N in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EAHOzX67VB8"
youtube_upload_date="2024-03-27"
youtube_thumbnail="https://i.ytimg.com/vi/EAHOzX67VB8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = n; i > n / 2; i--) {
            string b = bitset<32>(i).to_string();
            if(s.find(b.substr(b.find('1'))) == string::npos)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1016.md" >}}
---
{{< youtube EAHOzX67VB8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1017: Convert to Base -2](https://grid47.xyz/leetcode/solution-1017-convert-to-base-2/) |
| --- |
