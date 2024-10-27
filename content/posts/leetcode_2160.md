
+++
authors = ["Yasir"]
title = "Leetcode 2160: Minimum Sum of Four Digit Number After Splitting Digits"
date = "2018-11-29"
description = "Solution to Leetcode 2160"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/)

---

**Code:**

{{< highlight html >}}
class Solution{
public:
    int minimumSum(int num){
        string s = to_string(num);
        sort(s.begin(), s.end());
        int res = (s[0] - '0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';
        return res;
    }
};
{{< /highlight >}}

