
+++
authors = ["Crafted by Me"]
title = "Leetcode 1941: Check if All Characters Have Equal Number of Occurrences"
date = "2019-07-11"
description = "In-depth solution and explanation for Leetcode 1941: Check if All Characters Have Equal Number of Occurrences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1942: The Number of the Smallest Unoccupied Chair](https://grid47.xyz/posts/leetcode_1942) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

