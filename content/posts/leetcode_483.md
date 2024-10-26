
+++
authors = ["Yasir"]
title = "Leetcode 483: Smallest Good Base"
date = "2023-07-02"
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

{{< highlight html >}}
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

