
+++
authors = ["grid47"]
title = "Leetcode 969: Pancake Sorting"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 969: Pancake Sorting in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pancake-sorting/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        
        
        // find next largest
        // flip its index so that largest come first
        // flip one more time, so that the first goes to end
        
        vector<int> res;
        int i;
        for(int x = arr.size(); x > 0; x--) {
            for(i = 0; arr[i] != x; i++) {};
            reverse(arr.begin(), arr.begin() + i + 1);
            res.push_back(i + 1);
            reverse(arr.begin(), arr.begin() + x);
            res.push_back(x);
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/969.md" >}}
---
{{< youtube O8YUmSwQ2WU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #970: Powerful Integers](https://grid47.xyz/leetcode/solution-970-powerful-integers/) |
| --- |
