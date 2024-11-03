
+++
authors = ["Crafted by Me"]
title = "Leetcode 992: Subarrays with K Different Integers"
date = "2022-02-14"
description = "In-depth solution and explanation for Leetcode 992: Subarrays with K Different Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarrays-with-k-different-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k -1);
    }
    
    int atmost(vector<int>& nums, int k) {
        
        int res = 0, j = 0;
        map<int, int> ma;
        for(int i = 0; i < nums.size(); i++) {
            ma[nums[i]]++;
            if(ma[nums[i]] == 1) k--;
            
            while(k < 0) {
                ma[nums[j]]--;
                if(ma[nums[j]] == 0) k++;
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/992.md" >}}
---


| Next : [LeetCode #993: Cousins in Binary Tree](grid47.xyz/leetcode_993) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

