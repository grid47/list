
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1616: Split Two Strings to Make Palindrome"
date = "2020-05-28"
description = "Solution to Leetcode 1616"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-two-strings-to-make-palindrome/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }

    bool check(string a, string b) {
        int i = 0, j = a.size() -1;
        while(i < j && a[i] == b[j])
        i++, j--;
        return isPalindrom(a, i, j) || isPalindrom(b, i, j);
    }

    bool isPalindrom(string a, int i , int j) {
        while(i < j && a[i] == a[j])
        i++, j--;
        return i >= j;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

