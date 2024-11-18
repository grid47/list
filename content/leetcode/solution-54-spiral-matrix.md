
+++
authors = ["grid47"]
title = "Leetcode 54: Spiral Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 54: Spiral Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "fcn8qkRcFVM"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/54.webp"
+++



[`Problem Link`](https://leetcode.com/problems/spiral-matrix/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/54.webp" 
    alt="A glowing spiral matrix, gently unfurling and revealing numbers in soft concentric rings."
    caption="Solution to LeetCode 54: Spiral Matrix Problem"
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
    vector<int> spiralOrder(vector<vector<int>>& mtx) {
        int cBgn = 0, cEnd = mtx[0].size()  - 1;
        int rBgn = 0, rEnd = mtx.size() - 1;
        vector<int> ans;
        while(cBgn <= cEnd && rBgn <= rEnd) {
            for(int i = cBgn; i <= cEnd; i++)
                ans.push_back(mtx[rBgn][i]);
            rBgn++;
            for(int i = rBgn; i <= rEnd; i++)
                ans.push_back(mtx[i][cEnd]);
            cEnd--;
            if(rBgn <= rEnd)
            for(int i = cEnd; i >= cBgn; i--)
                ans.push_back(mtx[rEnd][i]);
            rEnd--;
            if(cBgn <= cEnd)            
            for(int i = rEnd; i >= rBgn; i--)
                ans.push_back(mtx[i][cBgn]);
            cBgn++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/54.md" >}}
---
{{< youtube fcn8qkRcFVM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #55: Jump Game](https://grid47.xyz/leetcode/solution-55-jump-game/) |
| --- |
