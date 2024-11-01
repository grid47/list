
+++
authors = ["Crafted by Me"]
title = "Leetcode 852: Peak Index in a Mountain Array"
date = "2022-07-04"
description = "Solution to Leetcode 852"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/peak-index-in-a-mountain-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();

        int l = 1, r = n - 2;

        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                return mid;
            }
            
            if(arr[mid] > arr[mid + 1]) {
                r = mid - 1;
            } else if(arr[mid] > arr[mid - 1]) {
                l = mid + 1;
            }
            
        }
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/852.md" >}}
---
{{< youtube yeYhFWpIus4 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

