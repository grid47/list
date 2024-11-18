
+++
authors = ["grid47"]
title = "Leetcode 2222: Number of Ways to Select Buildings"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2222: Number of Ways to Select Buildings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-select-buildings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long numberOfWays(string s) {

        typedef long long ll;

        int z = 0, o = 0;        
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '0') z++;
            if(s[i] == '1') o++;
            
        }

        int zl = 0, ol = 0;

        ll res = 0;
        
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '0') {
                res += (ol * (o - ol));
                
                zl++;
            }
            else if(s[i] == '1') {
                res += (zl * (z - zl));            
                
                ol++;
            }
                                    
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2222.md" >}}
---
{{< youtube EcQ0uhiF3HU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2224: Minimum Number of Operations to Convert Time](https://grid47.xyz/leetcode/solution-2224-minimum-number-of-operations-to-convert-time/) |
| --- |
