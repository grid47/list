
+++
authors = ["Yasir"]
title = "Leetcode 2239: Find Closest Number to Zero"
date = "2018-09-12"
description = "Solution to Leetcode 2239"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-closest-number-to-zero/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
  int findClosestNumber(vector<int>& nums) {
    return *min_element(begin(nums), end(nums), [](int a, int b) {
        return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
    });
  }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

