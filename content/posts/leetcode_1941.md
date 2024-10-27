
+++
authors = ["Yasir"]
title = "Leetcode 1941: Check if All Characters Have Equal Number of Occurrences"
date = "2019-07-06"
description = "Solution to Leetcode 1941"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26] = {}, m_cnt = 0;
        for (auto ch : s)
            m_cnt = max(m_cnt, ++cnt[ch - 'a']);
        return all_of(begin(cnt), end(cnt), [&m_cnt](int t){ return t == 0 || t == m_cnt; });
    }
};
{{< /highlight >}}

