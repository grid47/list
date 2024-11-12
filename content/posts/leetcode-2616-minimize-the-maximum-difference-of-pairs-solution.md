
+++
authors = ["grid47"]
title = "Leetcode 2616: Minimize the Maximum Difference of Pairs"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2616: Minimize the Maximum Difference of Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/)

---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), l = 0, r = nums[n - 1] - nums[0], ans = nums[n - 1] - nums[0];
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int k = p;
            for(int i = 1; i < n && k > 0; i++) {
                if(nums[i] - nums[i - 1] <= mid) {
                    k--;
                    i++;
                }
            }
            if(k == 0) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2616.md" >}}
---
{{< youtube lf1Pxg7IrzQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2617: Minimum Number of Visited Cells in a Grid](https://grid47.xyz/posts/leetcode-2617-minimum-number-of-visited-cells-in-a-grid-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
