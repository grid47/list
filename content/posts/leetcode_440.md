
+++
authors = ["Crafted by Me"]
title = "Leetcode 440: K-th Smallest in Lexicographical Order"
date = "2023-08-20"
description = "In-depth solution and explanation for Leetcode 440: K-th Smallest in Lexicographical Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
 public:
  int findKthNumber(long n, int k) {
    auto getGap = [&n](long a, long b) {
      long gap = 0;
      while (a <= n) {
        gap += min(n + 1, b) - a;
        a *= 10;
        b *= 10;
      }
      return gap;
    };

    long currNum = 1;

    for (int i = 1; i < k;) {
      long gap = getGap(currNum, currNum + 1);
      cout << currNum << " " << gap << "\n";
      if (i + gap <= k) {
        i += gap;
        ++currNum;
      } else {
        ++i;
        currNum *= 10;
      }
    }

    return currNum;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/440.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

