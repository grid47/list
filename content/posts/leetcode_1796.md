
+++
authors = ["Yasir"]
title = "Leetcode 1796: Second Largest Digit in a String"
date = "2019-11-28"
description = "Solution to Leetcode 1796"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/second-largest-digit-in-a-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int secondHighest(string s) {
        // support variables
        int res[2] = {-1, -1};
        // parsing s
        for (char c: s) {
            // considering only numerical characters
            if (c >= '0' && c <= '9') {
                // normalising c
                c -= '0';
                // updating res
                if (c > res[0]) {
                    res[1] = res[0];
                    res[0] = c;
                } else if (c != res[0] && c > res[1]) res[1] = c;
            }
        }
        return res[1];
    }
};
{{< /highlight >}}

