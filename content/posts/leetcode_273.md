
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 273: Integer to English Words"
date = "2024-01-30"
description = "Solution to Leetcode 273"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/integer-to-english-words/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};

    string helper(int n) {
        if (n < 20) 
            return ones[n];
        if (n < 100) 
            return tens[n / 10] + helper(n % 10);
        if (n < 1000) 
            return helper(n / 100) + " Hundred" + helper(n % 100);
        for (int i = 3; i >= 0; i--) {
            if (n >= pow(1000, i)) {
                return helper(n / pow(1000, i)) + thousands[i] + helper(n % (int)pow(1000, i));
            }
        }
        return "";
    }

    string numberToWords(int num) {
        if (num == 0)  return "Zero";
        return helper(num).substr(1);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

