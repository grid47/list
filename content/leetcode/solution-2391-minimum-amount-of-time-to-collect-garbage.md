
+++
authors = ["grid47"]
title = "Leetcode 2391: Minimum Amount of Time to Collect Garbage"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2391: Minimum Amount of Time to Collect Garbage in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last[128] = {}, res = 0;        
        for(int i = 0; i < garbage.size(); i++) {
            res += garbage[i].size();
            for(char c : garbage[i])
                last[c] = i;
        }

        for(int j = 1; j < travel.size(); j++)
            travel[j] += travel[j - 1];
        
        for(int c : "PGM")
        if(last[c])
        res += travel[last[c] - 1];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2391.md" >}}
---
{{< youtube gpjKAXQpOMM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2395: Find Subarrays With Equal Sum](https://grid47.xyz/leetcode/solution-2395-find-subarrays-with-equal-sum/) |
| --- |
