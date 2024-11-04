
+++
authors = ["Crafted by Me"]
title = "Leetcode 3120: Count the Number of Special Characters I"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 3120: Count the Number of Special Characters I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-special-characters-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> ch;
        for(char x: word)
                ch.insert(x);
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(ch.count('a' + i) && ch.count('A' + i))
                cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}


---
{{< youtube VV4TTRQ5l0s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3121: Count the Number of Special Characters II](https://grid47.xyz/posts/leetcode_3121) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

