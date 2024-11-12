
+++
authors = ["grid47"]
title = "Leetcode 852: Peak Index in a Mountain Array"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 852: Peak Index in a Mountain Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #853: Car Fleet](https://grid47.xyz/posts/leetcode-853-car-fleet-solution/) |
| --- |
