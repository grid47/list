
+++
authors = ["grid47"]
title = "Leetcode 2033: Minimum Operations to Make a Uni-Value Grid"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2033: Minimum Operations to Make a Uni-Value Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "c90k-5HigWs"
youtube_upload_date="2021-10-10"
youtube_thumbnail="https://i.ytimg.com/vi/c90k-5HigWs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m = grid.size(), n = grid[0].size();
        
        int num = grid[0][0];
        
        vector<int> arr;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            arr.push_back(grid[i][j]);
            if(abs(num - grid[i][j]) % x != 0) return -1;
        }
        
        sort(arr.begin(), arr.end());
        
        int pos = arr.size() / 2;

        int res = 0;
        for(int i = 0; i < arr.size(); i++)        
            res += (abs(arr[pos] - arr[i]) / x);
        
        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2033.md" >}}
---
{{< youtube c90k-5HigWs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2034: Stock Price Fluctuation ](https://grid47.xyz/leetcode/solution-2034-stock-price-fluctuation/) |
| --- |
