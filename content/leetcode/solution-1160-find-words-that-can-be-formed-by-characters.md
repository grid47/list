
+++
authors = ["grid47"]
title = "Leetcode 1160: Find Words That Can Be Formed by Characters"
date = "2024-07-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1160: Find Words That Can Be Formed by Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {}, res = 0;
        for (auto ch : chars) 
            ++cnt[ch - 'a'];
        for (auto &w : words) {
            int cnt1[26] = {}, match = true;
            for (auto ch : w)
            if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
                match = false;
                break;
            }
            if (match) 
                res += w.size();
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1160.md" >}}
---
{{< youtube riRpJLMdrXs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1161: Maximum Level Sum of a Binary Tree](https://grid47.xyz/leetcode/solution-1161-maximum-level-sum-of-a-binary-tree/) |
| --- |
