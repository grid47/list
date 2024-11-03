
+++
authors = ["Crafted by Me"]
title = "Leetcode 769: Max Chunks To Make Sorted"
date = "2022-09-25"
description = "In-depth solution and explanation for Leetcode 769: Max Chunks To Make Sorted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/769.md" >}}
---


"| 770: Basic Calculator IV |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

