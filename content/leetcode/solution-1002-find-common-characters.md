
+++
authors = ["grid47"]
title = "Leetcode 1002: Find Common Characters"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1002: Find Common Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-common-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> frq(26, INT_MAX);
        for(string& s: words) {
            vector<int> cnt(26, 0);
            for(char x: s) cnt[x - 'a']++;

            for(int i = 0; i < 26; i++)
            frq[i] = min(frq[i], cnt[i]);
        }

        vector<string> res;
        for(int i = 0; i < 26; i++)
        for(int j = 0; j < frq[i]; j++)
            res.push_back(string(1, 'a' + i));

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1002.md" >}}
---
{{< youtube QEESBA2Q_88 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1003: Check If Word Is Valid After Substitutions](https://grid47.xyz/leetcode/solution-1003-check-if-word-is-valid-after-substitutions/) |
| --- |
