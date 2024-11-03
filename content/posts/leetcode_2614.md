
+++
authors = ["Crafted by Me"]
title = "Leetcode 2614: Prime In Diagonal"
date = "2017-09-06"
description = "In-depth solution and explanation for Leetcode 2614: Prime In Diagonal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| Next : [LeetCode #2615: Sum of Distances](https://grid47.xyz/posts/leetcode_2615) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

