
+++
authors = ["Crafted by Me"]
title = "Leetcode 859: Buddy Strings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 859: Buddy Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/buddy-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int cnt = 0, fst = -1, scd = -1, cl = 0, fg = 0, t = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != goal[i]) {
                cnt++;
                if(fst == -1) fst = i;
                else if(scd == -1) scd = i;
            }
            if((fg >> (s[i] - 'a')) & 1) t = 1;
            fg |= (1 << (s[i] - 'a'));
        }
        
        if(cnt == 0) {
            if(t) return true;
            return false;
        }

        return (cnt == 2 && (s[fst] == goal[scd]) && (s[scd] == goal[fst]));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/859.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #860: Lemonade Change](https://grid47.xyz/posts/leetcode_860) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

