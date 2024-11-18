
+++
authors = ["grid47"]
title = "Leetcode 1664: Ways to Make a Fair Array"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1664: Ways to Make a Fair Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-make-a-fair-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int waysToMakeFair(vector<int>& nums) {

        vector<int> left(2, 0), right(2, 0);
        
        int n= nums.size(), res = 0;
        
        for(int i = 0; i < n; i++)
            right[i%2] += nums[i];
        
        for(int i = 0; i < n; i++) {
            right[i%2] -= nums[i];
            
            if(left[0] + right[1] == right[0] + left[1]) res++;
            
            left[i%2] += nums[i];
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1664.md" >}}
---
{{< youtube GS9BQo3-1mg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1668: Maximum Repeating Substring](https://grid47.xyz/leetcode/solution-1668-maximum-repeating-substring/) |
| --- |
