
+++
authors = ["grid47"]
title = "Leetcode 791: Custom Sort String"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 791: Custom Sort String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/791.webp"
youtube = "HQ4U24lRar8"
youtube_upload_date="2021-03-06"
youtube_thumbnail="https://i.ytimg.com/vi/HQ4U24lRar8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/custom-sort-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/791.webp" 
    alt="A string being sorted according to custom rules, with each valid sorting step glowing softly."
    caption="Solution to LeetCode 791: Custom Sort String Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string customSortString(string o, string s) {
        
        unordered_map<char, int> mp;
        for(int i = 0; i < o.size(); i++)
            mp[o[i]] = i + 1;
        
        sort(s.begin(), s.end(), [&](char a, char b) {
            return mp[a] < mp[b];
        });
        
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/791.md" >}}
---
{{< youtube HQ4U24lRar8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #792: Number of Matching Subsequences](https://grid47.xyz/leetcode/solution-792-number-of-matching-subsequences/) |
| --- |
