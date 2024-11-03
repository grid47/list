
+++
authors = ["Crafted by Me"]
title = "Leetcode 1855: Maximum Distance Between a Pair of Values"
date = "2019-10-05"
description = "In-depth solution and explanation for Leetcode 1855: Maximum Distance Between a Pair of Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


| Next : [LeetCode #1856: Maximum Subarray Min-Product](grid47.xyz/leetcode_1856) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

