
+++
authors = ["Yasir"]
title = "Leetcode 1846: Maximum Element After Decreasing and Rearranging"
date = "2019-10-09"
description = "Solution to Leetcode 1846"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        if(arr[0] != 1) arr[0] = 1;
        
        int n = arr.size();
        
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};
{{< /highlight >}}

