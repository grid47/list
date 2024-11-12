
+++
authors = ["grid47"]
title = "Leetcode 659: Split Array into Consecutive Subsequences"
date = "2024-09-02"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #662: Maximum Width of Binary Tree](https://grid47.xyz/posts/leetcode-662-maximum-width-of-binary-tree-solution/) |
| --- |
