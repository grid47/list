
+++
authors = ["Yasir"]
title = "Leetcode 769: Max Chunks To Make Sorted"
date = "2022-09-21"
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

