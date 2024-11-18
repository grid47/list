
+++
authors = ["grid47"]
title = "Leetcode 2087: Minimum Cost Homecoming of a Robot in a Grid"
date = "2024-04-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2087: Minimum Cost Homecoming of a Robot in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-ect7lESvLg"
youtube_upload_date="2021-11-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/-ect7lESvLg/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> row, col;
    vector<vector<long>> vis, vs;
    int m, n;
    
    int minCost(vector<int>& start, vector<int>& home, vector<int>& row, vector<int>& col) {
        m = row.size();
        n = col.size();
        int ans = 0;
        int i = start[0], x = home[0];
        int j = start[1], y = home[1];
        while(i != x) {
            i += (x - i) / abs(x - i);
            ans += row[i];
        }
        
        while(j != y) {
            j += (y - j) / abs(y - j);
            ans += col[j];
        }        
        return ans;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2087.md" >}}
---
{{< youtube -ect7lESvLg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2090: K Radius Subarray Averages](https://grid47.xyz/leetcode/solution-2090-k-radius-subarray-averages/) |
| --- |
