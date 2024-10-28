
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 880: Decoded String at Index"
date = "2022-06-02"
description = "Solution to Leetcode 880"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decoded-string-at-index/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    
    public:
    string decodeAtIndex(string s, int k) {
        
        long N = 0, i;
        
        for(i = 0; N < k; i++)
            N = isdigit(s[i])? (s[i] - '0') * N: N +1;
        
        while(i--) {
            if(isdigit(s[i])) {
                N /= (s[i] - '0');
                k %= N;
            }
            else if (k % N-- == 0) {
                return string(1, s[i]);
            }
        }
        
        return "hello yasir";
    }
    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

