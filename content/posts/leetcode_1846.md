
+++
authors = ["Crafted by Me"]
title = "Leetcode 1846: Maximum Element After Decreasing and Rearranging"
date = "2018-10-13"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

