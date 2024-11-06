
+++
authors = ["Crafted by Me"]
title = "Leetcode 2576: Find the Maximum Number of Marked Indices"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2576: Find the Maximum Number of Marked Indices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool can(int k, vector<int> &nums) {
        int ridx = k - 1;
        int lidx = nums.size() - k;
        
        for(int i = 0; i < k; i++)
            if(nums[i] * 2 > nums[nums.size() - k + i]) return false;
        
        return true;
        
    }
    
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, r = n/2, ans = 0;
        while(l <= r) {
            
            int mid = l + (r - l + 1) / 2;
            if(can(mid, nums)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;

        }
        return ans * 2;
    }
};
{{< /highlight >}}


---
{{< youtube NlsyXR7GOJE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2577: Minimum Time to Visit a Cell In a Grid](https://grid47.xyz/posts/leetcode_2577) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

