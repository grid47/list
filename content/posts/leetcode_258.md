
+++
authors = ["Yasir"]
title = "Leetcode 258: Add Digits"
date = "2024-02-14"
description = "Solution to Leetcode 258"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-digits/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        while(num > 9) {
            while(num > 0) {
                res += num % 10;
                num /= 10;
            }
            
            num = res;
            res = 0;
        }
        return num;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

