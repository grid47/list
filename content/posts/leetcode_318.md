
+++
authors = ["Crafted by Me"]
title = "Leetcode 318: Maximum Product of Word Lengths"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 318: Maximum Product of Word Lengths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-of-word-lengths/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProduct(vector<string>& words) {

        int len = words.size();
        vector<int> mask(len, 0);

        int res = 0;
        for(int i = 0; i < len; i++) {
            string word = words[i];
            int sz = word.size();
            for(int j = 0; j < sz; j++)
            mask[i] |= (1 << (word[j] - 'a'));

            for(int j = 0; j < i; j++) {
                if((mask[i] & mask[j]) == 0)
                res = max(res, int (words[i].size() * words[j].size() ));
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/318.md" >}}
---
{{< youtube dE88fgc73jQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #319: Bulb Switcher](https://grid47.xyz/posts/leetcode_319) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

