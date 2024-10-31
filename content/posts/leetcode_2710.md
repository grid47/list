
+++
authors = ["Crafted by Me"]
title = "Leetcode 2710: Remove Trailing Zeros From a String"
date = "2017-06-01"
description = "Solution to Leetcode 2710"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int cnt = 0;
        int len;
        for( len = 1; len <= n; len++) {
            if(num[n - len] == '0') cnt++;
            else break;
        }
        return num.substr(0, n - cnt);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

