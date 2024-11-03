
+++
authors = ["Crafted by Me"]
title = "Leetcode 372: Super Pow"
date = "2023-10-27"
description = "In-depth solution and explanation for Leetcode 372: Super Pow in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/372.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #373: Find K Pairs with Smallest Sums](https://grid47.xyz/posts/leetcode_373) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

