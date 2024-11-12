
+++
authors = ["grid47"]
title = "Leetcode 2696: Minimum String Length After Removing Substrings"
date = "2024-02-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2696: Minimum String Length After Removing Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2696.md" >}}
---
{{< youtube 8SD0rcmgFMU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2697: Lexicographically Smallest Palindrome](https://grid47.xyz/posts/leetcode-2697-lexicographically-smallest-palindrome-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
