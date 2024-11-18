
+++
authors = ["grid47"]
title = "Leetcode 13: Roman to Integer"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 13: Roman to Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "3jdxYj3DD98"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/13.webp"
+++



[`Problem Link`](https://leetcode.com/problems/roman-to-integer/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/13.webp" 
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #15: 3Sum](https://grid47.xyz/leetcode/solution-15-3sum/) |
| --- |
