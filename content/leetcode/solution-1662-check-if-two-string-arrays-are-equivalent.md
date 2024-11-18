
+++
authors = ["grid47"]
title = "Leetcode 1662: Check If Two String Arrays are Equivalent"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1662: Check If Two String Arrays are Equivalent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto x:word1)
            a += x;
        for(auto x:word2)
            b += x;
       
        if(a == b)
            return 1;
        
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1662.md" >}}
---
{{< youtube ejBwc2oE7ck >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1663: Smallest String With A Given Numeric Value](https://grid47.xyz/leetcode/solution-1663-smallest-string-with-a-given-numeric-value/) |
| --- |
