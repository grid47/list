
+++
authors = ["grid47"]
title = "Leetcode 13: Roman to Integer"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 13: Roman to Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/roman-to-integer/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/13.jpeg" 
    alt="Roman numerals transitioning into flowing numbers, visualizing transformation."
    caption="Solution to LeetCode 13: Roman to Integer Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #15: 3Sum](https://grid47.xyz/posts/leetcode-15-3sum-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
