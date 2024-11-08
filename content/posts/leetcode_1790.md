
+++
authors = ["grid47"]
title = "Leetcode 1790: Check if One String Swap Can Make Strings Equal"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1790: Check if One String Swap Can Make Strings Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int chg = 0, cnt = 0;
        vector<int> frq1(26, 0), frq2(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            frq1[s1[i] - 'a']++;
            frq2[s2[i] - 'a']++;
            if(s1[i] != s2[i]) cnt++;
        }

        return frq1 == frq2 && (cnt == 2 || cnt == 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1790.md" >}}
---
{{< youtube n4pxnAHTfeU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1791: Find Center of Star Graph](https://grid47.xyz/posts/leetcode_1791) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
