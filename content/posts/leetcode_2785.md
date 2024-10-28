
+++
authors = ["Yasir"]
title = "Leetcode 2785: Sort Vowels in a String"
date = "2017-03-15"
description = "Solution to Leetcode 2785"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-vowels-in-a-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'o'|| ch == 'u'|| ch == 'i';
    }
    string sortVowels(string s) {
        string v;
        copy_if(begin(s), end(s), back_inserter(v), [&](char ch){ 
            return isVowel(tolower(ch)); 
        });
        sort(begin(v), end(v));
        for (int i = 0, j = 0; i < s.size(); ++i)
            if (isVowel(tolower(s[i])))
                s[i] = v[j++];
        return s;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

