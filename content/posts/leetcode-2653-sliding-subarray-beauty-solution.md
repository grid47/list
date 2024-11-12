
+++
authors = ["grid47"]
title = "Leetcode 2653: Sliding Subarray Beauty"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2653: Sliding Subarray Beauty in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sliding-subarray-beauty/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<int> cnt;
    
    int no(int x) {
        int sum = 0;
        for(int i = 0; i <= 50; i++) {
            sum += cnt[i];
            if(sum >= x)
                return i - 50;
        }
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        cnt.resize(101, 0);
        
        vector<int> ans;
        
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            cnt[nums[i] + 50]++;            
        }
        ans.push_back(no(x));

        for(int i = k; i < n; i++) {
            cnt[nums[i] + 50]++;
            cnt[nums[i - k] + 50]--;
            
            ans.push_back(no(x));
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2653.md" >}}
---
{{< youtube ovFs2xad0_Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2654: Minimum Number of Operations to Make All Array Elements Equal to 1](https://grid47.xyz/posts/leetcode-2654-minimum-number-of-operations-to-make-all-array-elements-equal-to-1-solution/) |
| --- |
