
+++
authors = ["grid47"]
title = "Leetcode 1736: Latest Time by Replacing Hidden Digits"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1736: Latest Time by Replacing Hidden Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "d1hJCKlEGBM"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/d1hJCKlEGBM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string maximumTime(string t) {
        if(t[0]=='?' && t[1]=='?')
        {
            t[0]='2';
            t[1]='3';
        }
        if(t[0]=='?')
        {
            if(t[1]<='0')
                t[0]='2';
            else if(t[1]<='1')
                t[0]='2';
            else if(t[1]<='2')
                t[0]='2';
            else if(t[1]<='3')
                t[0]='2';
            else 
                t[0]='1';
        }
        if(t[1]=='?')
        {
            if(t[0]=='2')
                t[1]='3';
            else 
                t[1]='9';
        }
        if(t[3]=='?' && t[4]=='?')
        {
            t[3]='5';
            t[4]='9';
        }
        if(t[3]=='?')
        {
            t[3]='5';
        }
        if(t[4]=='?')
        {
            t[4]='9';
        }
        return t;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1736.md" >}}
---
{{< youtube d1hJCKlEGBM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1737: Change Minimum Characters to Satisfy One of Three Conditions](https://grid47.xyz/leetcode/solution-1737-change-minimum-characters-to-satisfy-one-of-three-conditions/) |
| --- |
