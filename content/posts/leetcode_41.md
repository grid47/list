
+++
authors = ["Crafted by Me"]
title = "Leetcode 41: First Missing Positive"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 41: First Missing Positive in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-missing-positive/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i]) {
                cout << nums[i] << " " << nums[nums[i] - 1] << "\n";
                swap(nums[i], nums[nums[i]-1]);      
                i--;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            // cout<< nums[i] << " " << i + 1 << "\n";
            if(nums[i] != i + 1)
                return i + 1;            
        }
        return nums.size() + 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/41.md" >}}
---
{{< youtube 8g78yfzMlao >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #42: Trapping Rain Water](https://grid47.xyz/posts/leetcode_42) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

