
+++
authors = ["grid47"]
title = "Leetcode 733: Flood Fill"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 733: Flood Fill in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flood-fill/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
    
    void dfs(vector<vector<int>> & img, int r, int c, int color, int node) {
        int m = img.size(), n = img[0].size();
        if (r < 0 || c < 0 || r == m || c == n || img[r][c] != node)
            return;
        
        img[r][c] = color;
        dfs(img, r + 1, c, color, node);
        dfs(img, r, c + 1, color, node);
        dfs(img, r - 1, c, color, node);
        dfs(img, r, c - 1, color, node);
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/733.md" >}}
---
{{< youtube NomjaXe6kUE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #735: Asteroid Collision](https://grid47.xyz/posts/leetcode-735-asteroid-collision-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
