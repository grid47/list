
+++
authors = ["Yasir"]
title = "Leetcode 400: Nth Digit"
date = "2023-09-24"
description = "Solution to Leetcode 400"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/nth-digit/description/)

---

**Code:**

{{< highlight html >}}
typedef long long int lli;
class Solution {
public:
    int findNthDigit(int n) {
        lli len = 1;
        lli cnt = 9;
        lli start = 1;
        while(n > len * cnt) {

            n -= len * cnt;
            
            len++;
            cnt *= 10;
            start *= 10;

        }
        start += (n - 1) / len;
        string s = to_string(start);     
        return s[(n - 1) % len] - '0';
    }
};
{{< /highlight >}}

