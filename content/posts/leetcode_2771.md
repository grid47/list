
+++
authors = ["Yasir"]
title = "Leetcode 2771: Longest Non-decreasing Subarray From Two Arrays"
date = "2017-03-28"
description = "Solution to Leetcode 2771"
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

{{< highlight html >}}
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

