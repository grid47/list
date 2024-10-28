
+++
authors = ["Yasir"]
title = "Leetcode 74: Search a 2D Matrix"
date = "2024-08-16"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

