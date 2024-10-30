
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 557: Reverse Words in a String III"
date = "2023-04-23"
description = "Solution to Leetcode 557"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), prv = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == ' ')
                rev(s, prv, i - 1), prv = i + 1;
            else if(i == n - 1)
                rev(s, prv, i);        
        return s;
    }
    
    void rev(string &s, int i, int j) {
        while(i <= j)
            swap(s[i++], s[j--]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/557.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

