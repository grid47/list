
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2697: Lexicographically Smallest Palindrome"
date = "2017-06-11"
description = "Solution to Leetcode 2697"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographically-smallest-palindrome/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        
        while(i < j) {
            char tmp = min(s[i], s[j]);
            s[i] = s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

