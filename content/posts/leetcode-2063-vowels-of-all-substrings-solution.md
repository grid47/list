
+++
authors = ["grid47"]
title = "Leetcode 2063: Vowels of All Substrings"
date = "2024-04-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2063: Vowels of All Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Dynamic Programming","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/vowels-of-all-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countVowels(string word) {
        long long res = 0, n = word.size();
        for(int i = 0; i < n; i++)
        if(string("aeiou").find(word[i]) != string::npos)
        res += (i + 1) * (n - i);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2063.md" >}}
---
{{< youtube yVDIm1IfG2c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2064: Minimized Maximum of Products Distributed to Any Store](https://grid47.xyz/posts/leetcode-2064-minimized-maximum-of-products-distributed-to-any-store-solution/) |
| --- |
