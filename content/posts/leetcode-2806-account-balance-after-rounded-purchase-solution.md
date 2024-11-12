
+++
authors = ["grid47"]
title = "Leetcode 2806: Account Balance After Rounded Purchase"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2806: Account Balance After Rounded Purchase in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/account-balance-after-rounded-purchase/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int accountBalanceAfterPurchase(int val) {
        
        if(val % 10 == 5) val += 5;
        else if(val % 10 > 5) {
            val = val / 10;
            val = (val + 1) * 10;
        } else {
            val = (val / 10) * 10;
        }
        return 100 - val;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2806.md" >}}
---
{{< youtube I3XEMabQJxE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2807: Insert Greatest Common Divisors in Linked List](https://grid47.xyz/posts/leetcode-2807-insert-greatest-common-divisors-in-linked-list-solution/) |
| --- |
