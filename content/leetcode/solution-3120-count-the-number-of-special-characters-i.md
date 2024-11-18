
+++
authors = ["grid47"]
title = "Leetcode 3120: Count the Number of Special Characters I"
date = "2023-12-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3120: Count the Number of Special Characters I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "VV4TTRQ5l0s"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-special-characters-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> ch;
        for(char x: word)
                ch.insert(x);
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(ch.count('a' + i) && ch.count('A' + i))
                cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3120.md" >}}
---
{{< youtube VV4TTRQ5l0s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3121: Count the Number of Special Characters II](https://grid47.xyz/leetcode/solution-3121-count-the-number-of-special-characters-ii/) |
| --- |
