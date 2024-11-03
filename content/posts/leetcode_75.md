
+++
authors = ["Crafted by Me"]
title = "Leetcode 75: Sort Colors"
date = "2024-08-19"
description = "In-depth solution and explanation for Leetcode 75: Sort Colors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-colors/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        
        for(int k = 0; k < n; k++) {
            
            while(nums[k] == 2 && k < j) {
                swap(nums[k], nums[j--]);                
            }
            while(nums[k] == 0 && k > i) {
                swap(nums[k], nums[i++]);  
            }
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/75.md" >}}
---
{{< youtube 4xbWSRZHqac >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #76: Minimum Window Substring](https://grid47.xyz/posts/leetcode_76) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

