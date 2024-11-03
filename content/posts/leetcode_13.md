
+++
authors = ["Crafted by Me"]
title = "Leetcode 13: Roman to Integer"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 13: Roman to Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Hash Table","Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/roman-to-integer/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int romanToInt(string s)
    {
        int ln = s.length();
        int res= RomToNum(s[ln-1]);
        int prv= res, curr = 0;
        for (int i = ln -2; i >=0; i--)
        {
            curr = RomToNum(s[i]);
            (curr < prv)? (res -= curr): (res += curr);
            prv = curr;
        }
        return res;
    }
    
    int RomToNum(char s)
    {
        switch (s)
        {
            case 'I' : return 1		;
            case 'V' : return 5		;
            case 'X' : return 10	;
            case 'L' : return 50	;
            case 'C' : return 100	;
            case 'D' : return 500	;
            case 'M' : return 1000	;
        }
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/13.md" >}}
---
{{< youtube 3jdxYj3DD98 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #14: Longest Common Prefix](https://grid47.xyz/posts/leetcode_14) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

