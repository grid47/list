
+++
authors = ["Crafted by Me"]
title = "Leetcode 2186: Minimum Number of Steps to Make Two Strings Anagram II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2186: Minimum Number of Steps to Make Two Strings Anagram II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> tsk(26, 0);
        for(char c: s)
        tsk[c - 'a']++;
        for(char c: t)
        tsk[c - 'a']--;

        int ans = 0;
        for(int a: tsk) ans += abs(a);
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube U7tKTEdd0Lw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2187: Minimum Time to Complete Trips](https://grid47.xyz/posts/leetcode_2187) |
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
