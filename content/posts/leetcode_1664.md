
+++
authors = ["Crafted by Me"]
title = "Leetcode 1664: Ways to Make a Fair Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1664: Ways to Make a Fair Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-make-a-fair-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int waysToMakeFair(vector<int>& nums) {

        vector<int> left(2, 0), right(2, 0);
        
        int n= nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
            right[i%2] += nums[i];
        
        for(int i = 0; i < n; i++) {
            right[i%2] -= nums[i];
            
            if(left[0] + right[1] == right[0] + left[1]) res++;
            
            left[i%2] += nums[i];
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1664.md" >}}
---
{{< youtube GS9BQo3-1mg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1665: Minimum Initial Energy to Finish Tasks](https://grid47.xyz/posts/leetcode_1665) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

