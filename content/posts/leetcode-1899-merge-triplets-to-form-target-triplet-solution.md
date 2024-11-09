
+++
authors = ["grid47"]
title = "Leetcode 1899: Merge Triplets to Form Target Triplet"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1901: Find a Peak Element II](https://grid47.xyz/posts/leetcode-1899-merge-triplets-to-form-target-triplet-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
