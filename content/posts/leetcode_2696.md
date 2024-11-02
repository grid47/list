
+++
authors = ["Crafted by Me"]
title = "Leetcode 2696: Minimum String Length After Removing Substrings"
date = "2016-06-15"
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


---
{{< youtube 8SD0rcmgFMU >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

