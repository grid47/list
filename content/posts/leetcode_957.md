
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 957: Prison Cells After N Days"
date = "2022-03-19"
description = "Solution to Leetcode 957"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/prison-cells-after-n-days/description/)

---
{{< youtube nan >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

