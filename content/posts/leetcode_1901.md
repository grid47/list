
+++
authors = ["Crafted by Me"]
title = "Leetcode 1901: Find a Peak Element II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1901: Find a Peak Element II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1901.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1902: Depth of BST Given Insertion Order](https://grid47.xyz/posts/leetcode_1902) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
