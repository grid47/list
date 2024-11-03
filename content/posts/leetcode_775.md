
+++
authors = ["Crafted by Me"]
title = "Leetcode 775: Global and Local Inversions"
date = "2022-09-19"
description = "In-depth solution and explanation for Leetcode 775: Global and Local Inversions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/global-and-local-inversions/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int cmax = 0, n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            cmax = max(cmax, nums[i]);
            if(cmax > nums[i + 2]) return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/775.md" >}}
---


"| 776: Split BST |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

