
+++
authors = ["Crafted by Me"]
title = "Leetcode 483: Smallest Good Base"
date = "2023-07-07"
description = "Solution to Leetcode 483"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-good-base/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
 public:
  string smallestGoodBase(string n) {
    const long num = stol(n);

    for (int m = log2(num); m >= 2; --m) {
      const int k = pow(num, 1.0 / m);
      long sum = 1;
      long prod = 1;
      for (int i = 0; i < m; ++i) {
        prod *= k;
        sum += prod;
      }
      if (sum == num)
        return to_string(k);
    }

    return to_string(num - 1);
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/483.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

