
+++
authors = ["grid47"]
title = "Leetcode 2411: Smallest Subarrays With Maximum Bitwise OR"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2411: Smallest Subarrays With Maximum Bitwise OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Bit Manipulation","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> ans(n, 1), last(30, 0);
        
        
        for(int i = n - 1; i >= 0; i--) {
            
            
            for(int j = 0; j < 30; j++) {
                
                if(nums[i] & (1 << j)) {
                    last[j] = i;
                }
                
                ans[i] = max(ans[i], last[j] - i + 1);
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2411.md" >}}
---
{{< youtube 0xR5bFyo2QA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2413: Smallest Even Multiple](https://grid47.xyz/posts/leetcode-2413-smallest-even-multiple-solution/) |
| --- |
