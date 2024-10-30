
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2299: Strong Password Checker II"
date = "2018-07-16"
description = "Solution to Leetcode 2299"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/strong-password-checker-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool strongPasswordCheckerII(string p) {
    int lo = 0, up = 0, digit = 0, sz = p.size();
    for (int i = 0; i < sz; ++i) {
        if (i > 0 && p[i - 1] == p[i])
            return false;
        lo += islower(p[i]) ? 1 : 0;
        up += isupper(p[i]) ? 1 : 0;
        digit += isdigit(p[i]) ? 1 : 0;
    }
    return sz > 7 && lo && up && digit && (sz - lo - up - digit > 0);
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

