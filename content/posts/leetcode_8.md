
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 8: String to Integer (atoi)"
date = "2024-10-22"
description = "Solution to Leetcode 8"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-to-integer-atoi/description/)

---
{{ youtube YA0LYrKI1CQ }}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int sgn = 1;
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        if(i < s.size() && (s[i] == '+' || s[i] == '-'))
            sgn = (s[i++] == '+')? 1: -1;
        
        while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
            
        if(res > INT_MAX/10 || 
        (res == INT_MAX/10 && ((s[i]-'0')>(INT_MAX %10))))
        return (sgn > 0)? INT_MAX: INT_MIN;
            
            res = res * 10 + (s[i++] - '0');
            // cout << res << " ";
        }
        
        return sgn * res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/8.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

