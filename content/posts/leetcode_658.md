
+++
authors = ["Crafted by Me"]
title = "Leetcode 658: Find K Closest Elements"
date = "2023-01-14"
description = "Solution to Leetcode 658"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-k-closest-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() -k;
        while(l < r) {
            int m = (l + r) / 2;
            if(x - arr[m] > arr[m + k] - x) {
                l = m + 1;
            } else r = m;
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/658.md" >}}
---
{{< youtube o-YDQzHoaKM >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

