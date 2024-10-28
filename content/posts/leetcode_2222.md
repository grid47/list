
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2222: Number of Ways to Select Buildings"
date = "2018-09-29"
description = "Solution to Leetcode 2222"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

