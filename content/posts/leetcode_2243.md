
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2243: Calculate Digit Sum of a String"
date = "2018-09-08"
description = "Solution to Leetcode 2243"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string digitSum(string s, int k) {
    while(s.size() > k) {
        string s1;
        for (int i = 0; i < s.size(); i += k)
            s1 += to_string(accumulate(begin(s) + i, begin(s) + min((int)s.size(), i + k), 0, 
                [](int n, char ch){ return n + ch - '0'; }));
        swap(s1, s);
    }
    return s;
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

