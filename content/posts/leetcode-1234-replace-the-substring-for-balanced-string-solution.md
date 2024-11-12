
+++
authors = ["grid47"]
title = "Leetcode 1234: Replace the Substring for Balanced String"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1234: Replace the Substring for Balanced String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int balancedString(string s) {
        map<char, int> ma;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
        }
        int k = s.size() / 4, j = 0, res = s.size();
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]--;
        while(j < s.size() && ma['Q'] <= k && ma['W'] <= k && ma['E'] <= k && ma['R'] <= k) {
                ma[s[j]]++;
                res = min(res, i - j + 1);
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1234.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1237: Find Positive Integer Solution for a Given Equation](https://grid47.xyz/posts/leetcode-1237-find-positive-integer-solution-for-a-given-equation-solution/) |
| --- |
