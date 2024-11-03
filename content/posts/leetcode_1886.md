
+++
authors = ["Crafted by Me"]
title = "Leetcode 1886: Determine Whether Matrix Can Be Obtained By Rotation"
date = "2019-09-04"
description = "In-depth solution and explanation for Leetcode 1886: Determine Whether Matrix Can Be Obtained By Rotation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        for(int i = 0; i < 4; i++) {
            if(match(mat, target)) return true;
            rotate(mat);
        }
        return false;
    }
    
    void rotate(vector<vector<int>>& mtx) {
        int n= mtx.size();
        int i = 0, j = n - 1;
        while(i <= j)
            swap(mtx[i++], mtx[j--]);
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            swap(mtx[i][j], mtx[j][i]);
    }
    
    bool match(vector<vector<int>>& mtx1, vector<vector<int>>& mtx2) {
        int n = mtx1.size();
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(mtx1[i][j] != mtx2[i][j])
                return false;
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1886.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1887: Reduction Operations to Make the Array Elements Equal](https://grid47.xyz/posts/leetcode_1887) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

