
+++
authors = ["grid47"]
title = "Leetcode 8: String to Integer (atoi)"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 8: String to Integer (atoi) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-to-integer-atoi/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/8.webp" 
    alt="A glowing number forming from abstract text, transforming from letters to digits."
    caption="Solution to LeetCode 8: String to Integer (atoi) Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
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
---
{{< youtube YA0LYrKI1CQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #9: Palindrome Number](https://grid47.xyz/posts/leetcode-9-palindrome-number-solution/) |
| --- |
