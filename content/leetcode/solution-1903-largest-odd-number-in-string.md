
+++
authors = ["grid47"]
title = "Leetcode 1903: Largest Odd Number in String"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1903: Largest Odd Number in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "IIt_ARZzclY"
youtube_upload_date="2021-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/IIt_ARZzclY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/largest-odd-number-in-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        for(int i = num.size(); i >= 0; i--) {
            if((num[i] - '0') % 2)
              return num.substr(0, i + 1);
        }
        return string();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1903.md" >}}
---
{{< youtube IIt_ARZzclY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1904: The Number of Full Rounds You Have Played](https://grid47.xyz/leetcode/solution-1904-the-number-of-full-rounds-you-have-played/) |
| --- |
