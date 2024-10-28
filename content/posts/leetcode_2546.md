
+++
authors = ["Yasir"]
title = "Leetcode 2546: Apply Bitwise Operations to Make Strings Equal"
date = "2017-11-09"
description = "Solution to Leetcode 2546"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        return (s.find('1') != string::npos) == (target.find('1') != string::npos);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

