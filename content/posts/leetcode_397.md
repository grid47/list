
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 397: Integer Replacement"
date = "2023-09-28"
description = "Solution to Leetcode 397"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/integer-replacement/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX) return 32;
        int cnt = 0;
        while(n > 1) {
            if(n % 2 == 0) n /= 2;
            else {
                if((n + 1) %4 == 0 && (n - 1) != 2) n++;
                else n--;
            }
            cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

