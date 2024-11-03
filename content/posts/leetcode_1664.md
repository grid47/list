
+++
authors = ["Crafted by Me"]
title = "Leetcode 1664: Ways to Make a Fair Array"
date = "2020-04-13"
description = "In-depth solution and explanation for Leetcode 1664: Ways to Make a Fair Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-make-a-fair-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int waysToMakeFair(vector<int>& nums) {

        vector<int> left(2, 0), right(2, 0);
        
        int n= nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
            right[i%2] += nums[i];
        
        for(int i = 0; i < n; i++) {
            right[i%2] -= nums[i];
            
            if(left[0] + right[1] == right[0] + left[1]) res++;
            
            left[i%2] += nums[i];
        }

        return res;
    }
};
{{< /highlight >}}


---


"| 1665: Minimum Initial Energy to Finish Tasks |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

