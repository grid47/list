
+++
authors = ["Yasir"]
title = "Leetcode 1497: Check If Array Pairs Are Divisible by k"
date = "2020-09-23"
description = "Solution to Leetcode 1497"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> frq(k, 0);
        for(int num : arr) {
            num %= k;
            if (num < 0) num += k;
            frq[num]++;
        }
        if(frq[0]%2 != 0) return false;
        for(int i = 1; i <= k/2; i++)
            if(frq[i] != frq[k - i]) return false;
        return true;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

