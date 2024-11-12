
+++
authors = ["grid47"]
title = "Leetcode 2734: Lexicographically Smallest String After Substring Operation"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2734: Lexicographically Smallest String After Substring Operation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while(i < s.size() && s[i] == 'a') i++;
        if(i >= s.size()) { s[s.size()-1] = 'z'; return s; }
        while(i < s.size() && s[i] != 'a') { s[i]--; i++; }
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2734.md" >}}
---
{{< youtube wvExCULvlqU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2735: Collecting Chocolates](https://grid47.xyz/posts/leetcode-2735-collecting-chocolates-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
