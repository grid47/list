
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2063: Vowels of All Substrings"
date = "2019-03-09"
description = "Solution to Leetcode 2063"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/vowels-of-all-substrings/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countVowels(string word) {
        long long res = 0, n = word.size();
        for(int i = 0; i < n; i++)
        if(string("aeiou").find(word[i]) != string::npos)
        res += (i + 1) * (n - i);
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

