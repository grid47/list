
+++
authors = ["Crafted by Me"]
title = "Leetcode 1935: Maximum Number of Words You Can Type"
date = "2019-07-17"
description = "In-depth solution and explanation for Leetcode 1935: Maximum Number of Words You Can Type in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


| Next : [LeetCode #1936: Add Minimum Number of Rungs](grid47.xyz/leetcode_1936) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

