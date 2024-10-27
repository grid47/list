
+++
authors = ["Yasir"]
title = "Leetcode 769: Max Chunks To Make Sorted"
date = "2022-09-20"
description = "Solution to Leetcode 769"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-chunks-to-make-sorted/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();

        int res = 0, mx = arr[0];

        for(int i = 0; i < n; i++) {
            
            mx = max(mx, arr[i]);
            res += (mx == i);
            
        }
        
        return res;
    }
};
{{< /highlight >}}

