
+++
authors = ["grid47"]
title = "Leetcode 2785: Sort Vowels in a String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2785: Sort Vowels in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-vowels-in-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'o'|| ch == 'u'|| ch == 'i';
    }
    string sortVowels(string s) {
        string v;
        copy_if(begin(s), end(s), back_inserter(v), [&](char ch){ 
            return isVowel(tolower(ch)); 
        });
        sort(begin(v), end(v));
        for (int i = 0, j = 0; i < s.size(); ++i)
            if (isVowel(tolower(s[i])))
                s[i] = v[j++];
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2785.md" >}}
---
{{< youtube ESF0Q-rrol0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2786: Visit Array Positions to Maximize Score](https://grid47.xyz/posts/leetcode-2786-visit-array-positions-to-maximize-score-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}