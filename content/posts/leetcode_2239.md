
+++
authors = ["Crafted by Me"]
title = "Leetcode 2239: Find Closest Number to Zero"
date = "2018-09-16"
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

{{< highlight cpp >}}
class Solution {
public:
  int findClosestNumber(vector<int>& nums) {
    return *min_element(begin(nums), end(nums), [](int a, int b) {
        return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
    });
  }
};
{{< /highlight >}}


---
{{< youtube dLlKA5DQKYs >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

