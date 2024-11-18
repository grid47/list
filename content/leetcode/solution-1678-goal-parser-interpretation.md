
+++
authors = ["grid47"]
title = "Leetcode 1678: Goal Parser Interpretation"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1678: Goal Parser Interpretation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "l-w3i4_PNUw"
youtube_upload_date="2020-12-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/l-w3i4_PNUw/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/goal-parser-interpretation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string interpret(string command) {
        string result= "";
        for(int i=0; i<command.size(); i++)
        {
            if(command[i] == '(')
            {
                if(command[i+1] == ')')
                    result += "o";
                if(command[i+1] == 'a' && command[i+2] == 'l')
                {
                    result += "al";
                    i += 2;
                }
            }
            if(command[i] == 'G')
                result += "G";
        }
        return result;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1678.md" >}}
---
{{< youtube l-w3i4_PNUw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1680: Concatenation of Consecutive Binary Numbers](https://grid47.xyz/leetcode/solution-1680-concatenation-of-consecutive-binary-numbers/) |
| --- |
