
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 762: Prime Number of Set Bits in Binary Representation"
date = "2022-09-28"
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

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

