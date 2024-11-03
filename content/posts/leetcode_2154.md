
+++
authors = ["Crafted by Me"]
title = "Leetcode 2154: Keep Multiplying Found Values by Two"
date = "2018-12-10"
description = "In-depth solution and explanation for Leetcode 2154: Keep Multiplying Found Values by Two in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int findFinalValue(vector<int>& nums, int o) {
        int h[1001]={};
        for(auto i:nums) h[i]++;
		
        while(o<=1000 && h[o])
            o*=2;
        
        return o;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2155: All Divisions With the Highest Score of a Binary Array](grid47.xyz/leetcode_2155) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

