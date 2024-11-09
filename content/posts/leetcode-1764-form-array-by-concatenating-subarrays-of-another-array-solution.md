
+++
authors = ["grid47"]
title = "Leetcode 1764: Form Array by Concatenating Subarrays of Another Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1764: Form Array by Concatenating Subarrays of Another Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canChoose(vector<vector<int>>& group, vector<int>& nums) {
        
        int numsIdx = 0, grpIdx = 0;
        
        while(numsIdx < nums.size() && grpIdx < group.size()) {
            

            int matchCnt = 0;
            
            while(numsIdx + matchCnt < nums.size() &&
                 matchCnt < group[grpIdx].size() &&
                 nums[numsIdx + matchCnt] == group[grpIdx][matchCnt])
                    matchCnt++;
            
            if(matchCnt == group[grpIdx].size()) {
                grpIdx++;
                numsIdx += matchCnt;
            } else numsIdx++;

        }
                
        return grpIdx == group.size();
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1764.md" >}}
---
{{< youtube GGdu6E9o7D4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1765: Map of Highest Peak](https://grid47.xyz/posts/leetcode-1765-map-of-highest-peak-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
