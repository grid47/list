
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2169: Count Operations to Obtain Zero"
date = "2018-11-22"
description = "Solution to Leetcode 2169"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-operations-to-obtain-zero/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 > 0 && num2 > 0) {
            if(num1 > num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ans++;
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

