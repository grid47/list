
+++
authors = ["Yasir"]
title = "Leetcode 762: Prime Number of Set Bits in Binary Representation"
date = "2022-09-27"
description = "Solution to Leetcode 762"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int prime[]={2, 3, 5, 7, 11, 13, 17, 19};
        vector<bool> isPrime(21, 0);
        for(int p: prime) isPrime[p]=1;
        int sum=0;
        for(int i=left; i<=right; i++){
            int b=__builtin_popcount(i);
            if (isPrime[b]) sum++;
        }
        return sum;
    }
};
{{< /highlight >}}

