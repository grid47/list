
+++
authors = ["grid47"]
title = "Leetcode 1704: Determine if String Halves Are Alike"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1704: Determine if String Halves Are Alike in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "n6svsUO6X8g"
youtube_upload_date="2020-12-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/n6svsUO6X8g/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/determine-if-string-halves-are-alike/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool halvesAreAlike(string s) {
        int t=0;
        for(int i=0;i<s.size();i++)
        {   
            s[i]=tolower(s[i]);
            if(i<s.size()/2)
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                      t++;                  // counting for the first half of the string
            }
            else
            {
                if(s[i]==97 || s[i]==101 || s[i]==105 || s[i]==111 || s[i]==117)
                     t--;            // reducing the count if occures in second half of the string 
            }     
        } 
       return (t==0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1704.md" >}}
---
{{< youtube n6svsUO6X8g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1705: Maximum Number of Eaten Apples](https://grid47.xyz/leetcode/solution-1705-maximum-number-of-eaten-apples/) |
| --- |
