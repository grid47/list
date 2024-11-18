
+++
authors = ["grid47"]
title = "Leetcode 2785: Sort Vowels in a String"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2785: Sort Vowels in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ESF0Q-rrol0"
youtube_upload_date="2023-07-22"
youtube_thumbnail="https://i.ytimg.com/vi/ESF0Q-rrol0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/sort-vowels-in-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'o'|| ch == 'u'|| ch == 'i';
    }
    string sortVowels(string s) {
        string v;
        copy_if(begin(s), end(s), back_inserter(v), [&](char ch){ 
            return isVowel(tolower(ch)); 
        });
        sort(begin(v), end(v));
        for (int i = 0, j = 0; i < s.size(); ++i)
            if (isVowel(tolower(s[i])))
                s[i] = v[j++];
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2785.md" >}}
---
{{< youtube ESF0Q-rrol0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2786: Visit Array Positions to Maximize Score](https://grid47.xyz/leetcode/solution-2786-visit-array-positions-to-maximize-score/) |
| --- |
