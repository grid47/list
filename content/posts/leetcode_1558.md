
+++
authors = ["Crafted by Me"]
title = "Leetcode 1558: Minimum Numbers of Function Calls to Make Target Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1558: Minimum Numbers of Function Calls to Make Target Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int cnt = 0;
        
        int n = nums.size();
        int zeros = 0;

        while(zeros != n) {
        
            for(int i = 0; i < n; i++) {

                if(nums[i] & 1) cnt++, nums[i]--;

            }
            
            zeros = 0;
            int ch = true;
            for(int i = 0; i < n; i++) {

                if(nums[i] > 0 && ch) cnt++, ch = false;
                
                nums[i] /= 2;

                if(nums[i] == 0) zeros++;
            }            
        }
        
        
        return cnt;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1558.md" >}}
---
{{< youtube CYAW6stML14 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1559: Detect Cycles in 2D Grid](https://grid47.xyz/posts/leetcode_1559) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
