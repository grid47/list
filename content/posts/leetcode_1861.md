
+++
authors = ["Crafted by Me"]
title = "Leetcode 1861: Rotating the Box"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1861: Rotating the Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1862: Sum of Floored Pairs](https://grid47.xyz/posts/leetcode_1862) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

