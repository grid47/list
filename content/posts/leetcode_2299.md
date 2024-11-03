
+++
authors = ["Crafted by Me"]
title = "Leetcode 2299: Strong Password Checker II"
date = "2018-07-18"
description = "In-depth solution and explanation for Leetcode 2299: Strong Password Checker II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


"| 2300: Successful Pairs of Spells and Potions |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

