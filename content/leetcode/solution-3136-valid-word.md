
+++
authors = ["grid47"]
title = "Leetcode 3136: Valid Word"
date = "2023-12-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3136: Valid Word in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "-sU51QkOwLY"
youtube_upload_date="2024-05-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-sU51QkOwLY/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/valid-word/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isValid(string word) {
        set<char> st;
        bool upper = false, lower = false;
        bool vowel = false, conso = false, number = false;
        
        for(char x : word) {
            
            if(x >= 'a' && x <= 'z') lower = true;
            if(x >= 'A' && x <= 'Z') upper = true;
            st.insert(x);
            if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
               x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                    vowel = true;
            else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
                    conso  = true;
            else if(isdigit(x)) {}
            else    return false;
            
        }
        
        return vowel && conso && st.size() >= 3;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3136.md" >}}
---
{{< youtube -sU51QkOwLY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3137: Minimum Number of Operations to Make Word K-Periodic](https://grid47.xyz/leetcode/solution-3137-minimum-number-of-operations-to-make-word-k-periodic/) |
| --- |
