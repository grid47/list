
+++
authors = ["grid47"]
title = "Leetcode 1861: Rotating the Box"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1861: Rotating the Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "2LRnTMOiqSI"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/rotating-the-box/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        reverse(box.begin(), box.end());
        
        int m = box.size(), n = box[0].size();
        vector<vector<char>> tmp(n, vector<char>(m));
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            tmp[j][i] = box[i][j];
        
        for(int i = 0; i < m; i++) {
            int k = n - 1;
            for(int j = n - 1; j >= 0; j--) {
                if(tmp[j][i] == '#') {
                    tmp[j][i] = '.'; // o
                    tmp[k][i] = '#'; // order is important
                    k--;
                } else if(tmp[j][i] == '*') {
                    k = j - 1;
                }else if(tmp[j][i] == '.') {
                    
                }
            }
        }
        return tmp; 
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1861.md" >}}
---
{{< youtube 2LRnTMOiqSI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1863: Sum of All Subset XOR Totals](https://grid47.xyz/leetcode/solution-1863-sum-of-all-subset-xor-totals/) |
| --- |
