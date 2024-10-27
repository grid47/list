
+++
authors = ["Yasir"]
title = "Leetcode 2177: Find Three Consecutive Integers That Sum to a Given Number"
date = "2018-11-12"
description = "Solution to Leetcode 2177"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num %3 != 0) return ans;
        return {num / 3 - 1, num/ 3, num/3 + 1};
    }
};
{{< /highlight >}}

