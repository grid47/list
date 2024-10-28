
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 848: Shifting Letters"
date = "2022-07-04"
description = "Solution to Leetcode 848"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shifting-letters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = shifts.size();
        for(int i = n - 2; i >= 0; i--)
        shifts[i] = (shifts[i] + shifts[i + 1] ) % 26;

        for(int i = 0; i < s.size(); i++)
        s[i] = 'a' + ((s[i] - 'a'+ shifts[i]) % 26);

        return s;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

