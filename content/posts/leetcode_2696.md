
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2696: Minimum String Length After Removing Substrings"
date = "2017-06-14"
description = "Solution to Leetcode 2696"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/)

---
{{< youtube 8SD0rcmgFMU >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        int res = n;
        for(int i = 0; i < n - 1; i++) {
            int p = i, q = i + 1;
            while((p >= 0 && q < n && s[p] == 'A' && s[q] == 'B') ||
               (p >= 0 && q < n && s[p] == 'C' && s[q] == 'D') ) {
                s[p] = 'X';
                s[q] = 'X';                
                res -= 2;
                while(q < n && s[q] == 'X') q++;
                while(p >= 0&& s[p] == 'X') p--;                
            }
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

