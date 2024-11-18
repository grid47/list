
+++
authors = ["grid47"]
title = "Leetcode 2712: Minimum Cost to Make All Characters Equal"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2712: Minimum Cost to Make All Characters Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "8MHnlNroHaU"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumCost(string s) {
        /*
        
        0100111
        
        0000000 3 + 2 + 1        
        
        1011111 4 + 2 + 1   if odd len choose middle
        
        0101000
        1011111 3 + 3 + 2 + 1         
        0100000 4 + 3 + 2 + 1 if odd len choose middle
        
        010111
        
        011011
        
        011011  0/ 2 + 3 + 1
                1/ 3 + 2 + 1
        
        010011
        
        010000  2 + 2 + 1
        
        101111  3
        011111  3 + 2
        111111  3 + 2 + 1 = 6
        
        010000  3 = 3
        100000  3 + 2 = 5
        000000  3 + 2 + 1 = 6
        
        */
        
        int n = s.size();
        
        if(n == 1) return 0;
        long long res = 0;

        char k = s[n / 2];
        
        int i, j;
        
        if(n % 2)
            i = n/2 + 1, j = n/2 - 1;
        else i = n/2, j = n / 2 - 1;
            bool ltog = true, rtog = true;
            while(i < n && j >= 0) {
                if(s[i] == k && rtog || s[i] != k && !rtog) {
                } else {
                    rtog = !rtog;
                    res += n - i;
                }
                i++;
                if((s[j] == k && ltog) || (s[j] != k && !ltog)) {
                } else {
                    ltog = !ltog;
                    res += j + 1;
                }
                j--;                
            }
            return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2712.md" >}}
---
{{< youtube 8MHnlNroHaU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2716: Minimize String Length](https://grid47.xyz/leetcode/solution-2716-minimize-string-length/) |
| --- |
