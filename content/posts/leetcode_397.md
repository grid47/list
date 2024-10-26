
+++
authors = ["Yasir"]
title = "Leetcode 397: Integer Replacement"
date = "2023-09-26"
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

{{< highlight html >}}
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

