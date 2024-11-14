
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
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/733.webp" 
    alt="A grid where the flood fill algorithm is applied, with the flooded area glowing softly as it spreads."
    caption="Solution to LeetCode 733: Flood Fill Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #735: Asteroid Collision](https://grid47.xyz/posts/leetcode-735-asteroid-collision-solution/) |
| --- |
