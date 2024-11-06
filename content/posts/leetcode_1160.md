
+++
authors = ["Crafted by Me"]
title = "Leetcode 1160: Find Words That Can Be Formed by Characters"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1161: Maximum Level Sum of a Binary Tree](https://grid47.xyz/posts/leetcode_1161) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
