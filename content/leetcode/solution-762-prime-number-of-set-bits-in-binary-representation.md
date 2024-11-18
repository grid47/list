
+++
authors = ["grid47"]
title = "Leetcode 762: Prime Number of Set Bits in Binary Representation"
date = "2024-08-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 762: Prime Number of Set Bits in Binary Representation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/762.webp" 
    alt="A set of binary numbers where the prime number of set bits is calculated, each prime set bit glowing softly."
    caption="Solution to LeetCode 762: Prime Number of Set Bits in Binary Representation Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/762.md" >}}
---
{{< youtube KeCWKJxsyxA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #763: Partition Labels](https://grid47.xyz/leetcode/solution-763-partition-labels/) |
| --- |
