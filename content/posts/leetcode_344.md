
+++
authors = ["Yasir"]
title = "Leetcode 344: Reverse String"
date = "2023-11-20"
description = "Solution to Leetcode 344"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            swap(s[i++], s[j--]);
        }
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

