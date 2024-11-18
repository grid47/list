
+++
authors = ["grid47"]
title = "Leetcode 957: Prison Cells After N Days"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 957: Prison Cells After N Days in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "mQQp6I985bw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/prison-cells-after-n-days/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        set<vector<int>> seen;
        int i = 0, flag = 0;
        vector<int> c;
        for(i = 0; i < n; i++) {
            vector<int> v = getNext(cells);
            if(!seen.count(v)) {
                seen.insert(v);
                cells = v;
            } else {
                for(int j = 0; j < n % i; j++) {
                    cells = getNext(cells);
                }
                return cells;
            }
        }
        return cells;
    }
    
    vector<int> getNext(vector<int> &cells) {
        vector<int> n(cells.size(), 0);
        for(int i = 1; i < cells.size() -1; i++)
            n[i] = cells[i-1] == cells[i+1]?1:0;
        return n;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/957.md" >}}
---
{{< youtube mQQp6I985bw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #958: Check Completeness of a Binary Tree](https://grid47.xyz/leetcode/solution-958-check-completeness-of-a-binary-tree/) |
| --- |
