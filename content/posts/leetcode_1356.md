
+++
authors = ["Crafted by Me"]
title = "Leetcode 1356: Sort Integers by The Number of 1 Bits"
date = "2020-02-15"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

