
+++
authors = ["Crafted by Me"]
title = "Leetcode 74: Search a 2D Matrix"
date = "2024-08-20"
description = "Solution to Leetcode 74"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/search-a-2d-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mtx, int target) {
        int m = mtx.size(), n = mtx[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = l + (r - l) /2;
            int rw = mid / n, c = mid % n, val = mtx[rw][c];
                 if(val == target) return true;
            else if(val  > target) r = mid - 1;
            else                   l = mid + 1;
        }
        return false;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/74.md" >}}
- by gpt
        
---
{{< youtube x-dYOtIudzc >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

