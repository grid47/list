
+++
authors = ["grid47"]
title = "Leetcode 1899: Merge Triplets to Form Target Triplet"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1899: Merge Triplets to Form Target Triplet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& tgt) {
        vector<int> res(3, 0);
        int n = tri.size();

        for(auto s: tri) {
            if(s[0] <= tgt[0] && s[1] <= tgt[1] && s[2] <= tgt[2]) {
                res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
            }
        }
        
        return tgt == res;        
    }
    
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1899.md" >}}
---
{{< youtube kShkQLQZ9K4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1901: Find a Peak Element II](https://grid47.xyz/leetcode/solution-1901-find-a-peak-element-ii/) |
| --- |
