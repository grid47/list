
+++
authors = ["Crafted by Me"]
title = "Leetcode 767: Reorganize String"
date = "2022-09-26"
description = "Solution to Leetcode 767"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reorganize-string/description/)

---

{{< youtube 2g_b1aYTHeg >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reorganizeString(string s) {
        int mfq = 0, i = 0;
        
        vector<int> frq(26, 0);
        for(char c: s)
            if (++frq[c - 'a'] > frq[mfq])
                mfq = c - 'a';
        
        // if mfq over bounds return ""
        if(2 * frq[mfq] - 1 > s.size()) return "";
        /*  dist mfq across
            dist rest across */
        while(frq[mfq]) {
            s[i] = 'a' + mfq;
            i += 2;
            frq[mfq]--;
        }

        for(int j = 0; j < 26; j++) {
            while(frq[j]) {
                if(i >= s.size()) i = 1;
                s[i] = 'a' + j;
                frq[j]--;
                i += 2;
            }
        }
        
        return s;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/767.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

