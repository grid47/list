
+++
authors = ["Crafted by Me"]
title = "Leetcode 2828: Check if a String Is an Acronym of Words"
date = "2017-02-03"
description = "Solution to Leetcode 2828"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res = "";
        for(string w: words)
            res += w[0];
        return s == res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

