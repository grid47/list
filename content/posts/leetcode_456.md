
+++
authors = ["Crafted by Me"]
title = "Leetcode 456: 132 Pattern"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 456: 132 Pattern in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/132-pattern/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        int prv = INT_MIN;
        stack<int> stk;
        
        for(int i = n - 1; i >= 0; i--) {

            if (nums[i] < prv) return true;

            while(!stk.empty() && nums[i] > stk.top()) {

                prv = stk.top();
                stk.pop();

            }

            stk.push(nums[i]);
        }

        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/456.md" >}}
---
{{< youtube TfgWauHLuRE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #457: Circular Array Loop](https://grid47.xyz/posts/leetcode_457) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

