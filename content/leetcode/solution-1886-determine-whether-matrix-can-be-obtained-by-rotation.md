
+++
authors = ["grid47"]
title = "Leetcode 1886: Determine Whether Matrix Can Be Obtained By Rotation"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1886: Determine Whether Matrix Can Be Obtained By Rotation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "vf_nUx64R0E"
youtube_upload_date="2021-06-06"
youtube_thumbnail="https://i.ytimg.com/vi/vf_nUx64R0E/maxresdefault.jpg"
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
{{< youtube vf_nUx64R0E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1887: Reduction Operations to Make the Array Elements Equal](https://grid47.xyz/leetcode/solution-1887-reduction-operations-to-make-the-array-elements-equal/) |
| --- |
