
+++
authors = ["Yasir"]
title = "Leetcode 1400: Construct K Palindrome Strings"
date = "2020-12-29"
description = "Solution to Leetcode 1400"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-k-palindrome-strings/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool canConstruct(string s, int k) {
        bitset<26> odd;
        for(char c: s)
        odd.flip(c - 'a');
        return odd.count() <= k && k <= s.size();
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

