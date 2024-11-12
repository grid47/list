
+++
authors = ["grid47"]
title = "Leetcode 1493: Longest Subarray of 1's After Deleting One Element"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1493: Longest Subarray of 1's After Deleting One Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        
        int ans = 0;
        
        int n = nums.size();
        
        int k = 1;
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) k--;
            
            while(k < 0) {
                if(nums[j] == 0)
                    k++;
                j++;
            }
            ans = max(ans, i - j);
        }
        
        /*
        i - j mean one elment will be cut from [j, i] closed interval
        what k does is, make that element a zero.
        */

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1493.md" >}}
---
{{< youtube PnzvwU4CFg8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1496: Path Crossing](https://grid47.xyz/posts/leetcode-1496-path-crossing-solution/) |
| --- |
