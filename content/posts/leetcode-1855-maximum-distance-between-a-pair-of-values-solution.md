
+++
authors = ["grid47"]
title = "Leetcode 1855: Maximum Distance Between a Pair of Values"
date = "2024-05-05"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1859: Sorting the Sentence](https://grid47.xyz/posts/leetcode-1859-sorting-the-sentence-solution/) |
| --- |
