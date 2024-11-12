
+++
authors = ["grid47"]
title = "Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    // time/space: O(n)/O(1)
    int minChanges(string s) {
        int result = 0;
        int n = s.size();
        for (int i = 0; i < n; i += 2) {
            const char& a = s[i];
            const char& b = s[i + 1];
            if (a != b) result++;
        }        
        return result;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2914.md" >}}
---
{{< youtube mzozXxrB_fk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2915: Length of the Longest Subsequence That Sums to Target](https://grid47.xyz/posts/leetcode-2915-length-of-the-longest-subsequence-that-sums-to-target-solution/) |
| --- |
