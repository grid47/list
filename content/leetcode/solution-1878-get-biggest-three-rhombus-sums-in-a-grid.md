
+++
authors = ["grid47"]
title = "Leetcode 1878: Get Biggest Three Rhombus Sums in a Grid"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1878: Get Biggest Three Rhombus Sums in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Sorting","Heap (Priority Queue)","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "KAuzn8OcGXk"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    typedef long long ll;
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> s;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int sz = 0; i + sz < m && i - sz >= 0 && j + 2 * sz < n; sz++) {
                    
                    ll x = i, y = j, rsum = 0;
                    do rsum += grid[x++][y++]; while(x < i + sz);
                    if(sz > 0) {
                        
                        do rsum += grid[x--][y++]; while(y < j + 2 * sz);
                        do rsum += grid[x--][y--]; while(x > i - sz);
                        do rsum += grid[x++][y--]; while(x < i);
                        
                    }
                    s.insert(rsum);
                    if(s.size() > 3) {
                        s.erase(begin(s));}
                }
                }
            }
        return vector<int>(rbegin(s), rend(s));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1878.md" >}}
---
{{< youtube KAuzn8OcGXk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1880: Check if Word Equals Summation of Two Words](https://grid47.xyz/leetcode/solution-1880-check-if-word-equals-summation-of-two-words/) |
| --- |
