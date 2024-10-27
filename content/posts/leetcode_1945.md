
+++
authors = ["Yasir"]
title = "Leetcode 1945: Sum of Digits of String After Convert"
date = "2019-07-02"
description = "Solution to Leetcode 1945"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int getLucky(string s, int k) {
        string tmp;
        for (char c : s) tmp += to_string(c - 'a' + 1);
        int n = 0;
        for (char c : tmp) n += c - '0';
        for (int i = 1; i < k; ++i) {
            int next = 0;
            while (n) {
                next += n % 10;
                n /= 10;
            }
            n = next;
        }
        return n;
    }
};
{{< /highlight >}}

