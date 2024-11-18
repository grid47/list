
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
youtube = "8SD0rcmgFMU"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2697: Lexicographically Smallest Palindrome](https://grid47.xyz/leetcode/solution-2697-lexicographically-smallest-palindrome/) |
| --- |
