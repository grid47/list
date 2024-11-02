
+++
authors = ["Crafted by Me"]
title = "Leetcode 162: Find Peak Element"
date = "2023-05-24"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/162.md" >}}
---
{{< youtube 31foR5tJapQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

