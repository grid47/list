
+++
authors = ["grid47"]
title = "Leetcode 205: Isomorphic Strings"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 205: Isomorphic Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/205.webp"
youtube = "WIJcGWvzu24"
youtube_upload_date="2022-06-26"
youtube_thumbnail="https://i.ytimg.com/vi/WIJcGWvzu24/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/isomorphic-strings/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/205.webp" 
    alt="Two strings gently morphing into each other, with glowing connections between each corresponding character."
    caption="Solution to LeetCode 205: Isomorphic Strings Problem"
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
    bool isIsomorphic(string s, string t) {
       
         
        map<char, char> fwd, rwd;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if (fwd.count(s[i])){
                if(fwd[s[i]] != t[i])
                    return false;
            }
            if(rwd.count(t[i])){
                if(rwd[t[i]] != s[i])
                    return false;
            }
            fwd[s[i]] = t[i];
            rwd[t[i]] = s[i];
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/205.md" >}}
---
{{< youtube WIJcGWvzu24 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #206: Reverse Linked List](https://grid47.xyz/leetcode/solution-206-reverse-linked-list/) |
| --- |