
+++
authors = ["grid47"]
title = "Leetcode 2404: Most Frequent Even Element"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2404: Most Frequent Even Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/most-frequent-even-element/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for(auto n: nums) mp[n]++;
        int ans = -1, mx = -1;
        for(auto m: mp){
            if(m.first%2 == 0 && m.second > mx){
                mx = m.second;
                ans = m.first;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2404.md" >}}
---
{{< youtube JykfDvn2o0M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2405: Optimal Partition of String](https://grid47.xyz/leetcode/solution-2405-optimal-partition-of-string/) |
| --- |
