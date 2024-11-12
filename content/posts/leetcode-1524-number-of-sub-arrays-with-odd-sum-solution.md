
+++
authors = ["grid47"]
title = "Leetcode 1524: Number of Sub-arrays With Odd Sum"
date = "2024-06-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1524: Number of Sub-arrays With Odd Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
      int odd = 0, even = 0, sum = 0;
        for(int x : arr) {
            
            if (x % 2) {
                
                swap(odd, even);
                odd++;
                
                } else even++;
            
            sum = (sum + odd) % 1000000007;
            
            }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1524.md" >}}
---
{{< youtube B5affGy4mCs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1525: Number of Good Ways to Split a String](https://grid47.xyz/posts/leetcode-1525-number-of-good-ways-to-split-a-string-solution/) |
| --- |
