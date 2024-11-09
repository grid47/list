
+++
authors = ["grid47"]
title = "Leetcode 376: Wiggle Subsequence"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 376: Wiggle Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/wiggle-subsequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int wiggleMaxLength(vector<int> nums) {
        if(nums.size() == 0) return 0;
        
        int n = nums.size();
        
        vector<int> up(n, 0);
        vector<int> down(n, 0);        
        
        up[0] = 1;
        down[0] = 1;
        
        for(int i = 1; i < n; i++) {
                 if(nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else if(nums[i] > nums[i - 1]) {            
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];                
            }
            else {
                down[i] = down[i - 1];
                up[i]   =   up[i - 1];                
            }
        }
        
        return max(down[n - 1], up[n - 1]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/376.md" >}}
---
{{< youtube IpWoZvKzpug >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #377: Combination Sum IV](https://grid47.xyz/posts/leetcode-376-wiggle-subsequence-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
