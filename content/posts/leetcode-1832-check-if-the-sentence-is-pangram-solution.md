
+++
authors = ["grid47"]
title = "Leetcode 1832: Check if the Sentence Is Pangram"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1832: Check if the Sentence Is Pangram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkIfPangram(string set) {
        bitset<26> bit;
        for(char x: set) bit.set(x - 'a');
        return bit.count() == 26;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1832.md" >}}
---
{{< youtube rk82ArzlPHM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1833: Maximum Ice Cream Bars](https://grid47.xyz/posts/leetcode-1833-maximum-ice-cream-bars-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
