
+++
authors = ["grid47"]
title = "Leetcode 3146: Permutation Difference between Two Strings"
date = "2023-12-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3146: Permutation Difference between Two Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "fHFotCayOiU"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/permutation-difference-between-two-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<t.length();j++)
            {
                if(s[i]==t[j])
                 sum+=abs(i-j);
            }
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3146.md" >}}
---
{{< youtube fHFotCayOiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3162: Find the Number of Good Pairs I](https://grid47.xyz/leetcode/solution-3162-find-the-number-of-good-pairs-i/) |
| --- |
