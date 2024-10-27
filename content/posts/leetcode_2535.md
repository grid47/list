
+++
authors = ["Yasir"]
title = "Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array"
date = "2017-11-19"
description = "Solution to Leetcode 2535"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
int dsum(int v) {
    return v == 0 ? 0 : v % 10 + dsum(v / 10);
}
int differenceOfSum(vector<int>& n) {
    return abs(accumulate(begin(n), end(n), 0) - 
        accumulate(begin(n), end(n), 0, [&](int s, int v){ return s + dsum(v); }));
}
};
{{< /highlight >}}

