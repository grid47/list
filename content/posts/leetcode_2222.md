
+++
authors = ["Crafted by Me"]
title = "Leetcode 2222: Number of Ways to Select Buildings"
date = "2024-11-01"
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


---
{{< youtube EcQ0uhiF3HU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2223: Sum of Scores of Built Strings](https://grid47.xyz/posts/leetcode_2223) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

