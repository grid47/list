
+++
authors = ["Yasir"]
title = "Leetcode 733: Flood Fill"
date = "2022-10-25"
description = "Solution to Leetcode 733"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flood-fill/description/)

---

**Code:**

{{< highlight html >}}
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

