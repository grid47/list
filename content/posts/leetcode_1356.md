
+++
authors = ["Yasir"]
title = "Leetcode 1356: Sort Integers by The Number of 1 Bits"
date = "2021-02-10"
description = "Solution to Leetcode 1356"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/)

---

**Code:**

{{< highlight html >}}
// class cmp {
//     public:
//     bool operator() (int a, int b) {
//         int x = __builtin_popcount(a);
//         int y = __builtin_popcount(b);
//         if(x == y) return a < b;
//         return x < y;
//     }
// };

bool cmp(int a, int b) {
        int x = __builtin_popcount(a);
        int y = __builtin_popcount(b);
        if(x == y) return a < b;
        return x < y;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), cmp);

        return arr;
    }
};
{{< /highlight >}}

