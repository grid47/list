
+++
authors = ["grid47"]
title = "Leetcode 954: Array of Doubled Pairs"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 954: Array of Doubled Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/array-of-doubled-pairs/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        unordered_map<int, int> c;
        for(int i : arr)
            c[i]++;
        
        vector<int> keys;
        for(auto it: c)
            keys.push_back(it.first);
        
        sort(keys.begin(), keys.end(), [&](int a, int b){
            return abs(a) < abs(b);
        });
        
        for(int x: keys) {
            if(c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/954.md" >}}
---
{{< youtube Q0WKzdpR74o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #955: Delete Columns to Make Sorted II](https://grid47.xyz/leetcode/solution-955-delete-columns-to-make-sorted-ii/) |
| --- |
