
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2000: Reverse Prefix of Word"
date = "2019-05-11"
description = "Solution to Leetcode 2000"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-prefix-of-word/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto p = word.find(ch);
        if (p != string::npos)
            reverse(begin(word), begin(word) + p + 1);
        return word;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

