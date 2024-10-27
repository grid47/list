
+++
authors = ["Yasir"]
title = "Leetcode 1855: Maximum Distance Between a Pair of Values"
date = "2019-09-30"
description = "Solution to Leetcode 1855"
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

{{< highlight html >}}
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

