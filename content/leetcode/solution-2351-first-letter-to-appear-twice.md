
+++
authors = ["grid47"]
title = "Leetcode 2351: First Letter to Appear Twice"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2351: First Letter to Appear Twice in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "zIFHijNYeCE"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/first-letter-to-appear-twice/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26);
        for(char c:s){
            v[c-'a']++;
            if(v[c-'a']>1)return c;
        }
        return 'a';
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2351.md" >}}
---
{{< youtube zIFHijNYeCE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2352: Equal Row and Column Pairs](https://grid47.xyz/leetcode/solution-2352-equal-row-and-column-pairs/) |
| --- |
