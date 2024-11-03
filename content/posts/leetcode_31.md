
+++
authors = ["Crafted by Me"]
title = "Leetcode 31: Next Permutation"
date = "2024-10-02"
description = "In-depth solution and explanation for Leetcode 31: Next Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/next-permutation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) { 
                idx = i;
                break;
            }
        }
        if(idx ==-1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size() - 1; i > idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[idx], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/31.md" >}}
---
{{< youtube 6qXO72FkqwM >}}

"| 32: Longest Valid Parentheses |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

