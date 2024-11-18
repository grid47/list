
+++
authors = ["grid47"]
title = "Leetcode 1750: Minimum Length of String After Deleting Similar Ends"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1750: Minimum Length of String After Deleting Similar Ends in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "318hrWVr_5U"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumLength(string s) {
        vector<int> pre(3, 0), suf(3, 0);
        
        int i = 0, j = s.size() - 1, len = s.size();
        while(i < j && s[i] == s[j]) {
            char c = s[i];
            while(i < j && s[i] == c) i++;
            while(i < j && s[j] == c) j--;

            len = min(len, j == i? s[i-1]!=s[j]: (j - i + 1));
        }
        return len;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1750.md" >}}
---
{{< youtube 318hrWVr_5U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1752: Check if Array Is Sorted and Rotated](https://grid47.xyz/leetcode/solution-1752-check-if-array-is-sorted-and-rotated/) |
| --- |
