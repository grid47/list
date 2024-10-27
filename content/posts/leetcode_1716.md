
+++
authors = ["Yasir"]
title = "Leetcode 1716: Calculate Money in Leetcode Bank"
date = "2020-02-16"
description = "Solution to Leetcode 1716"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/)

---

**Code:**

{{< highlight html >}}

class Solution {
public:
    int totalMoney(int n) {
        int s = 1, ans = 0;
        while (n > 0) {
            for (int i = 0; i < 7 && n-- > 0; ++i) ans += s + i;
            s++;
        }
        return ans;
    }
};
{{< /highlight >}}

