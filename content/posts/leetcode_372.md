
+++
authors = ["Yasir"]
title = "Leetcode 372: Super Pow"
date = "2023-10-22"
description = "Solution to Leetcode 372"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/super-pow/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
    int base = 1337;
    int powmod(int a, int k) {
        a %= base;
        int res = 1;
        for(int i = 0; i < k; i++)
        res = (res * a) % base;
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};
{{< /highlight >}}

