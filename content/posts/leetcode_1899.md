
+++
authors = ["Yasir"]
title = "Leetcode 1899: Merge Triplets to Form Target Triplet"
date = "2019-08-18"
description = "Solution to Leetcode 1899"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

