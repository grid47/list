
+++
authors = ["Crafted by Me"]
title = "Leetcode 704: Binary Search"
date = "2022-11-29"
description = "In-depth solution and explanation for Leetcode 704: Binary Search in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-search/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/704.md" >}}
---
{{< youtube PissfOvEH7Q >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #705: Design HashSet](https://grid47.xyz/posts/leetcode_705) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

