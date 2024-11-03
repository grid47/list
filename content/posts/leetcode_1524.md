
+++
authors = ["Crafted by Me"]
title = "Leetcode 1524: Number of Sub-arrays With Odd Sum"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1524: Number of Sub-arrays With Odd Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1525: Number of Good Ways to Split a String](https://grid47.xyz/posts/leetcode_1525) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

