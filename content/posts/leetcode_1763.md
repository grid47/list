
+++
authors = ["Crafted by Me"]
title = "Leetcode 1763: Longest Nice Substring"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1763: Longest Nice Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-nice-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string longestNiceSubstring(string s, int start = 0, int end = -1) {
        if (end == -1)
            end = s.size();
        int cnt[26][2] = {}, j = start - 1;
        for (auto i = start; i < end; ++i)
            cnt[tolower(s[i]) - 'a'][(bool)islower(s[i])] = 1;
        string res;
        for (auto i = start; i <= end; ++i) {
            int ch = i == end ? -1 : tolower(s[i]) - 'a';
            if (ch == -1 || cnt[ch][0] + cnt[ch][1] == 1) {
                if (j == -1 && ch == -1)
                    return s;
                auto res1 = longestNiceSubstring(s.substr(j + 1, i - j - 1));
                if (res1.size() > res.size())
                    res = res1;
                j = i;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1763.md" >}}
---
{{< youtube 6WvZrynlCdk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1764: Form Array by Concatenating Subarrays of Another Array](https://grid47.xyz/posts/leetcode_1764) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

