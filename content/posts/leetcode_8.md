
+++
authors = ["Yasir"]
title = "Leetcode 8: String to Integer (atoi)"
date = "2024-10-17"
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

**Code:**

{{< highlight html >}}
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

