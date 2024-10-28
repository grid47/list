
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1524: Number of Sub-arrays With Odd Sum"
date = "2020-08-27"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

