
+++
authors = ["Crafted by Me"]
title = "Leetcode 1901: Find a Peak Element II"
date = "2019-08-20"
description = "Solution to Leetcode 1901"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-a-peak-element-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        int l = 0, r = n - 1;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            
            int row = 0;
            for(int i = 0; i < m; i++)
                row = mat[i][mid] >= mat[row][mid]? i: row;
            
            int isRightLarger = mid + 1 <= r ? mat[row][mid + 1] > mat[row][mid]: false;
            int isLeftLarger = mid - 1 >= l  ? mat[row][mid - 1] > mat[row][mid]: false;            
            
            if(!isRightLarger && !isLeftLarger)
                return vector<int>{row, mid};
            
            if(isRightLarger) l = mid + 1;
            else             r = mid - 1;
            
        }
        return vector<int>{-1, -1};
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

