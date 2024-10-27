
+++
authors = ["Yasir"]
title = "Leetcode 2087: Minimum Cost Homecoming of a Robot in a Grid"
date = "2019-02-10"
description = "Solution to Leetcode 2087"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/)

---

**Code:**

{{< highlight html >}}
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

