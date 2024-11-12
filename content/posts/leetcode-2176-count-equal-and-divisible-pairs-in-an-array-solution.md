
+++
authors = ["grid47"]
title = "Leetcode 2176: Count Equal and Divisible Pairs in an Array"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2176: Count Equal and Divisible Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> umap;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(umap.find(nums[i]) != umap.end()) 
            {
                for(auto x : umap[nums[i]]) 
                    if((i * x) % k == 0)
                        count++;
            }
            
            umap[nums[i]].push_back(i);
        }
        return count;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2176.md" >}}
---
{{< youtube 25az-hMz2YE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2177: Find Three Consecutive Integers That Sum to a Given Number](https://grid47.xyz/posts/leetcode-2177-find-three-consecutive-integers-that-sum-to-a-given-number-solution/) |
| --- |
