
+++
authors = ["Yasir"]
title = "Leetcode 1017: Convert to Base -2"
date = "2022-01-15"
description = "Solution to Leetcode 1017"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-to-base-2/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string baseNeg2(int n) {
        string res = "";

        while(n) {
            res = to_string(n&1) + res;
            n = -(n >> 1);
        }

        return res == ""? "0":res;
    }
};
{{< /highlight >}}

