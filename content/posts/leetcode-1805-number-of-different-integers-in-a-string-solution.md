
+++
authors = ["grid47"]
title = "Leetcode 1805: Number of Different Integers in a String"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1805: Number of Different Integers in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-different-integers-in-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numDifferentIntegers(string w) {
        unordered_set<string> s{""};    
        for (int i = 0, j = 0; j <= w.size(); ++j) {
            if (j < w.size() && isdigit(w[j]))
                i += i < j && w[i] == '0';
            else {
                s.insert(w.substr(i, j - i));
                i = j + 1;
            }
        }
        return s.size() - 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1805.md" >}}
---
{{< youtube 1vZ2c92YgOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1806: Minimum Number of Operations to Reinitialize a Permutation](https://grid47.xyz/posts/leetcode-1806-minimum-number-of-operations-to-reinitialize-a-permutation-solution/) |
| --- |
