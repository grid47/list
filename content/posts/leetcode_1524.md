
+++
authors = ["Crafted by Me"]
title = "Leetcode 1524: Number of Sub-arrays With Odd Sum"
date = "2019-08-31"
description = "Solution to Leetcode 1524"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

