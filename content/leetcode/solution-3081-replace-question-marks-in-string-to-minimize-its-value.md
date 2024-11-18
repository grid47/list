
+++
authors = ["grid47"]
title = "Leetcode 3081: Replace Question Marks in String to Minimize Its Value"
date = "2024-01-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3081: Replace Question Marks in String to Minimize Its Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> frq(26, 0), taken;

        int n = s.size();
        for(char c: s) if(c != '?') frq[c - 'a']++;

        for(int i = 0; i < n; i++) {
            if(s[i] != '?') continue;

            int mn = 0;
            for(int j = 0; j < 26; j++)
                if(frq[j] < frq[mn]) mn = j;

            taken.push_back(mn);
            frq[mn]++;
        }

        sort(taken.begin(), taken.end());

        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?')
            s[i] = taken[idx++] + 'a';
        }

        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3081.md" >}}
---
{{< youtube dYPKJ4Kelxw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3099: Harshad Number](https://grid47.xyz/leetcode/solution-3099-harshad-number/) |
| --- |
