
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 984: String Without AAA or BBB"
date = "2022-02-18"
description = "Solution to Leetcode 984"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-without-aaa-or-bbb/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
        if(B > A) return strWithout3a3b(B, A, b, a);
        while(A-- > 0) {
            res += a;
            if(A > B) res += a, A--;
            if(B-->0) res += b;
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

