
+++
authors = ["Crafted by Me"]
title = "Leetcode 2771: Longest Non-decreasing Subarray From Two Arrays"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2771: Longest Non-decreasing Subarray From Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int Boom(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = 1;
        vector<int> dp1(n, 1), dp2(n, 1);
                
        for(int i = 1; i < n; i++) {         
            for(int j = 0; j < i; j++) {
                if(nums1[i] >= nums1[j]) {
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
                if(nums1[i] >= nums2[j]) {
                   dp1[i] = max(dp1[i], dp2[j] + 1);                    
                }
                if(nums2[i] >= nums1[j]) {
                    dp2[i] = max(dp2[i], dp1[j] + 1);                    
                }                 
                if(nums2[i] >= nums2[j]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);                                        
                }
            }
            ans = max(ans, max(dp1[i], dp2[i]));          
        }
        
        return ans;
    }
    
    
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = 1;
        vector<int> dp1(n, 1), dp2(n, 1);
                
        for(int i = 1; i < n; i++) {         
            if(nums1[i] >= nums1[i - 1]) {
                dp1[i] = max(dp1[i], dp1[i - 1] + 1);
            }
            if(nums1[i] >= nums2[i - 1]) {
               dp1[i] = max(dp1[i], dp2[i - 1] + 1);                    
            }
            if(nums2[i] >= nums1[i - 1]) {
                dp2[i] = max(dp2[i], dp1[i - 1] + 1);                    
            }                 
            if(nums2[i] >= nums2[i - 1]) {
                dp2[i] = max(dp2[i], dp2[i - 1] + 1);                                        
            }
            ans = max(ans, max(dp1[i], dp2[i]));          
        }
        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube 2aJYkQsBRbI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2772: Apply Operations to Make All Array Elements Equal to Zero](https://grid47.xyz/posts/leetcode_2772) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

