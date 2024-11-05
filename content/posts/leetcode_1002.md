
+++
authors = ["Crafted by Me"]
title = "Leetcode 1002: Find Common Characters"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1002: Find Common Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-common-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> frq(26, INT_MAX);
        for(string& s: words) {
            vector<int> cnt(26, 0);
            for(char x: s) cnt[x - 'a']++;

            for(int i = 0; i < 26; i++)
            frq[i] = min(frq[i], cnt[i]);
        }

        vector<string> res;
        for(int i = 0; i < 26; i++)
        for(int j = 0; j < frq[i]; j++)
            res.push_back(string(1, 'a' + i));

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1002.md" >}}
---
{{< youtube QEESBA2Q_88 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1003: Check If Word Is Valid After Substitutions](https://grid47.xyz/posts/leetcode_1003) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

