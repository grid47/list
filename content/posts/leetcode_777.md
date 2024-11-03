
+++
authors = ["Crafted by Me"]
title = "Leetcode 777: Swap Adjacent in LR String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 777: Swap Adjacent in LR String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["String","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/swap-adjacent-in-lr-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        string s1, s2;
        for (int i = 0; i < n; ++i) 
            if (start[i] != 'X') s1 += start[i];
        for (int i = 0; i < n; ++i) 
            if (end[i] != 'X') s2 += end[i];
        if (s1 != s2) return false;

        int p1 = 0, p2 = 0;
        while(p1 < start.size() && p2 < end.size()) {
            while(p1 < start.size() && start[p1] == 'X') p1++;
            while(p2 < end.size()   && end[p2]   == 'X') p2++;

            if(p1 == start.size() && p2 == end.size()) return true;
            if(p1 == start.size() || p2 == end.size()) return false;

            if(start[p1] != end[p2]) return false;

            if(start[p1] == 'L' && p2 > p1) return false;
            if(start[p1] == 'R' && p2 < p1) return false;
            p1++;
            p2++;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/777.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #778: Swim in Rising Water](https://grid47.xyz/posts/leetcode_778) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

