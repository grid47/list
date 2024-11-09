
+++
authors = ["grid47"]
title = "Leetcode 1671: Minimum Number of Removals to Make Mountain Array"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1671: Minimum Number of Removals to Make Mountain Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Greedy"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int lis(vector<int> arr) {
        vector<int> res;
        for(int i = 0; i < arr.size(); i++) {
            int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            if(idx == res.size()) res.push_back(arr[i]);
            else res[idx] = arr[i];
        }
        return res.size();
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        int mx = 0;
        
        for(int i = 1; i < n - 1; i++) {

            vector<int> left;
            for(int k = 0; k < i; k++) {
                if(nums[k] < nums[i]) left.push_back(nums[k]);
            }
            left.push_back(nums[i]);
            vector<int> right;
            right.push_back(nums[i]);
            for(int k = i + 1; k < n; k++) {
                if(nums[k] < nums[i]) right.push_back(nums[k]);
            }
            reverse(right.begin(), right.end());
            int a = lis(left);
            int b = lis(right);
            if(a >= 2 && b >= 2) {
                mx = max(mx, a + b - 1);
            }
        }
        
        return nums.size() - mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1671.md" >}}
---
{{< youtube Ys-q9qPpleY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1672: Richest Customer Wealth](https://grid47.xyz/posts/leetcode-1671-minimum-number-of-removals-to-make-mountain-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
