
+++
authors = ["Yasir"]
title = "Leetcode 869: Reordered Power of 2"
date = "2022-06-11"
description = "Solution to Leetcode 869"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reordered-power-of-2/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int c = counter(n);
        for(int i = 0; i < 32; i++)
            if(counter(1<<i) == c) return true;
        return false;
    }

    int counter(int N) {
        int res = 0;
        for(;N; N/=10) res += pow(10, N%10);
        return res;
    }
};
{{< /highlight >}}

