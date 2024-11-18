
+++
authors = ["grid47"]
title = "Leetcode 1418: Display Table of Food Orders in a Restaurant"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1418: Display Table of Food Orders in a Restaurant in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<unordered_map<string, int>> table(501);
        set<string> s;
        
        for(vector<string> &v : orders) {
            s.insert(v[2]);
            ++table[stoi(v[1])][v[2]];
        }
        
        vector<vector<string>> res;
        for(int t = 0; t < 501; t++) {
            if (t > 0 && table[t].empty()) {
continue;
            }
            res.push_back(vector<string>());
            res.back().push_back(t == 0 ? "Table" : to_string(t));
            for(auto it = begin(s); it != end(s); it++) {
                
                res.back().push_back(t == 0? *it : to_string(table[t][*it]));
                
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1418.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1419: Minimum Number of Frogs Croaking](https://grid47.xyz/leetcode/solution-1419-minimum-number-of-frogs-croaking/) |
| --- |
