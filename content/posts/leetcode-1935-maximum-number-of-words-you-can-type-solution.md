
+++
authors = ["grid47"]
title = "Leetcode 1935: Maximum Number of Words You Can Type"
date = "2024-04-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1935: Maximum Number of Words You Can Type in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {};
        for (auto ch : brokenLetters)
            broken[ch - 'a'] = true;
        int res = 0, cnt = 0;
        for (auto ch : text)
            if (ch == ' ') {
                res += cnt == 0;
                cnt = 0;
            }
            else
                cnt += broken[ch - 'a'];
        return res + (cnt == 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1935.md" >}}
---
{{< youtube FLMJwdw9Kqc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1936: Add Minimum Number of Rungs](https://grid47.xyz/posts/leetcode-1936-add-minimum-number-of-rungs-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
