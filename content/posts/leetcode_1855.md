
+++
authors = ["Crafted by Me"]
title = "Leetcode 1855: Maximum Distance Between a Pair of Values"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1855: Maximum Distance Between a Pair of Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++) {
                
                int l = i, r = nums2.size() - 1, j = i;

                int target = nums1[i]; // find larget index which satisfies target <= nums[i]
            
                while(l <= r) {
                    int mid = l + (r - l + 1) / 2;
                    
                    if(target < nums2[mid]) {
                        j = mid;
                        l = mid + 1;
                    } else if(target > nums2[mid]) {
                        r = mid - 1;
                    } else if(target == nums2[mid]) {
                        j = mid;
                        l = mid + 1;
                    }

                }
                // cout << j - i;
                
                ans = max(ans, j - i);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1855.md" >}}
---
{{< youtube ksN__viaDFs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1856: Maximum Subarray Min-Product](https://grid47.xyz/posts/leetcode_1856) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
