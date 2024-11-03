
+++
authors = ["Crafted by Me"]
title = "Leetcode 1418: Display Table of Food Orders in a Restaurant"
date = "2020-12-15"
description = "In-depth solution and explanation for Leetcode 1418: Display Table of Food Orders in a Restaurant in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

| Next : [LeetCode #1419: Minimum Number of Frogs Croaking](https://grid47.xyz/posts/leetcode_1419) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

