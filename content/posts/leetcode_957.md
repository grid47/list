
+++
authors = ["Yasir"]
title = "Leetcode 957: Prison Cells After N Days"
date = "2022-03-15"
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

**Code:**

{{< highlight html >}}
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

