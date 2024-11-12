
+++
authors = ["grid47"]
title = "Leetcode 2614: Prime In Diagonal"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2614: Prime In Diagonal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Matrix","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/prime-in-diagonal/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  // seive
  bool isPrime(int n){
      if (n <= 2 || n % 2 == 0) 
          return n == 2;
      for (int i = 3; i * i <= n; i += 2)
          if (n % i == 0)
              return false;
      return true;
  }      
  int diagonalPrime(vector<vector<int>>& n) {
      int p = 0;
      for (int i = 0; i < n.size(); ++i)
          p = max({p, isPrime(n[i][i]) * n[i][i], 
              isPrime(n[i][n.size() - i - 1]) * n[i][n.size() - i - 1]});
      return p;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2614.md" >}}
---
{{< youtube PEKRvVTWf4g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2615: Sum of Distances](https://grid47.xyz/posts/leetcode-2615-sum-of-distances-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
