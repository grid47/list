
+++
authors = ["grid47"]
title = "Leetcode 2104: Sum of Subarray Ranges"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2104: Sum of Subarray Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "sMFAjHe3kkw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-subarray-ranges/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long res = 0, n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            
            int mini = nums[i], maxi = nums[i];
            
            for(int j = i + 1; j < n; j++) {
                
                if(nums[j] < mini) mini = nums[j];
                if(nums[j] > maxi) maxi = nums[j];
                res += maxi - mini;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2104.md" >}}
---
{{< youtube sMFAjHe3kkw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2105: Watering Plants II](https://grid47.xyz/leetcode/solution-2105-watering-plants-ii/) |
| --- |
