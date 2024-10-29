
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 13: Roman to Integer"
date = "2024-10-17"
description = "Solution to Leetcode 13"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

