
+++
authors = ["Crafted by Me"]
title = "Leetcode 768: Max Chunks To Make Sorted II"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 768: Max Chunks To Make Sorted II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int,int>> tmp;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            tmp.push_back({arr[i], i});
        }
        sort(tmp.begin(), tmp.end());
        int res = 0, mx = -1;
        for(int i = 0; i < n; i++) {
            mx = max(mx, tmp[i].second);
            if(mx == i){
                res++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/768.md" >}}
---
{{< youtube 6jrh2Gn0KiQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #769: Max Chunks To Make Sorted](https://grid47.xyz/posts/leetcode_769) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

