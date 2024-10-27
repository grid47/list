
+++
authors = ["Yasir"]
title = "Leetcode 2283: Check if Number Has Equal Digit Count and Digit Value"
date = "2018-07-29"
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

{{< highlight html >}}
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

