
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value"
date = "2018-07-30"
description = "Solution to Leetcode 2283"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
bool digitCount(string num) {
    int cnt[10] = {};
    for (auto n : num)
        ++cnt[n - '0'];
    for (int i = 0; i < num.size(); ++i)
        if (cnt[i] != num[i] - '0')
            return false;
    return true;
}
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

