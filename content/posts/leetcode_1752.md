
+++
authors = ["Crafted by Me"]
title = "Leetcode 1752: Check if Array Is Sorted and Rotated"
date = "2020-01-16"
description = "In-depth solution and explanation for Leetcode 1752: Check if Array Is Sorted and Rotated in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #1753: Maximum Score From Removing Stones](grid47.xyz/leetcode_1753) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

