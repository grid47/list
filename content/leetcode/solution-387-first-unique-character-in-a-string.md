
+++
authors = ["grid47"]
title = "Leetcode 387: First Unique Character in a String"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 387: First Unique Character in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Queue","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/387.webp"
youtube = "nFiAUwTH0zY"
youtube_upload_date="2020-05-05"
youtube_thumbnail="https://i.ytimg.com/vi/nFiAUwTH0zY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/first-unique-character-in-a-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/387.webp" 
    alt="A glowing string with the first unique character softly highlighted."
    caption="Solution to LeetCode 387: First Unique Character in a String Problem"
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
    int firstUniqChar(string s) {
        
        map<char, int> mp;
        for(char x: s) mp[x]++;
        
        for(int i = 0; i < s.size(); i++)
            if(mp[s[i]] == 1) return i;
        
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/387.md" >}}
---
{{< youtube nFiAUwTH0zY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #388: Longest Absolute File Path](https://grid47.xyz/leetcode/solution-388-longest-absolute-file-path/) |
| --- |
