
+++
authors = ["grid47"]
title = "Leetcode 659: Split Array into Consecutive Subsequences"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 659: Split Array into Consecutive Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        
        for(int num: nums)
            left[num]++;

        for(int num: nums) { // nums is in increasing order
            if(left[num] == 0) continue;
            
            left[num]--;
            
            if(end[num - 1] > 0) {
                end[num - 1]--;
                end[num]++;
            }
            else if(left[num + 1] > 0 && left[num + 2] > 0) {
                left[num + 1]--;
                left[num + 2]--;
                end [num + 2]++;
            } else return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/659.md" >}}
---
{{< youtube hbNUEvWyiFU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #660: Remove 9](https://grid47.xyz/posts/leetcode-659-split-array-into-consecutive-subsequences-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
