
+++
authors = ["grid47"]
title = "Leetcode 2576: Find the Maximum Number of Marked Indices"
date = "2024-02-23"
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2576.md" >}}
---
{{< youtube NlsyXR7GOJE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2577: Minimum Time to Visit a Cell In a Grid](https://grid47.xyz/posts/leetcode-2577-minimum-time-to-visit-a-cell-in-a-grid-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
