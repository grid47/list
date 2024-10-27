
+++
authors = ["Yasir"]
title = "Leetcode 162: Find Peak Element"
date = "2024-05-19"
description = "Solution to Leetcode 162"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-peak-element/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        
        int l = 0, r = n - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            bool x = mid > 0? arr[mid - 1] < arr[mid] : true;
            bool y = mid < n -1 ? arr[mid + 1] < arr[mid] : true;
            
            if(x && y) return mid;
            if(!x && y) r = mid - 1;
            else if(x && !y) l = mid + 1;
            else r = mid - 1;            
        }
        return l;
    }
};
{{< /highlight >}}

