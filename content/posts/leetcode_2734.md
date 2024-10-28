
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2734: Lexicographically Smallest String After Substring Operation"
date = "2017-05-05"
description = "Solution to Leetcode 2734"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while(i < s.size() && s[i] == 'a') i++;
        if(i >= s.size()) { s[s.size()-1] = 'z'; return s; }
        while(i < s.size() && s[i] != 'a') { s[i]--; i++; }
        return s;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

