
+++
authors = ["Yasir"]
title = "Leetcode 2154: Keep Multiplying Found Values by Two"
date = "2018-12-05"
description = "Solution to Leetcode 2154"
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

{{< highlight html >}}
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

