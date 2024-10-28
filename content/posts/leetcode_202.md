
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 202: Happy Number"
date = "2024-04-10"
description = "Solution to Leetcode 202"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/happy-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sqr(int n) {
        int res = 0;
        while(n) {
            int tmp = n % 10;
            res += tmp * tmp;
            n = n / 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sqr(slow);
            fast = sqr(sqr(fast));
        } while(slow != fast);
        return slow == 1;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

