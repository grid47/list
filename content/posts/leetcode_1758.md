
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1758: Minimum Changes To Make Alternating Binary String"
date = "2020-01-06"
description = "Solution to Leetcode 1758"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(string s) {
        int zero = 0, one = 0, zf = false, of = false;
        for(int i = 0; i < s.size(); i++) {
            if(zf   && s[i] == '0') zero++;
            if(!zf  && s[i] == '1') zero++;
            if(!of   && s[i] == '0') one++;
            if(of  && s[i] == '1') one++;
            zf = !zf, of = !of;
        }
        return min(zero, one);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

