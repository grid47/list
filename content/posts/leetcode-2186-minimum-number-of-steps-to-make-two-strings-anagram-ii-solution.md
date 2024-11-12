
+++
authors = ["grid47"]
title = "Leetcode 2186: Minimum Number of Steps to Make Two Strings Anagram II"
date = "2024-04-02"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2186.md" >}}
---
{{< youtube U7tKTEdd0Lw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2187: Minimum Time to Complete Trips](https://grid47.xyz/posts/leetcode-2187-minimum-time-to-complete-trips-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
