
+++
authors = ["grid47"]
title = "Leetcode 2708: Maximum Strength of a Group"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2708: Maximum Strength of a Group in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Greedy","Bit Manipulation","Sorting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-strength-of-a-group/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        
        bool zero = false, allneg = true, allzero = true, pos = false;
        
        int ncnt = 0, pcnt = 0;
        
        long long ans = 1, neg = 1;
        int mxn = -10;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                pcnt++;
                pos = true;
                allzero = false;
                allneg = false;
                ans *= nums[i];
            } else if(nums[i] == 0) {
                zero = true;
            } else {
                ncnt++;
                allzero = false;                
                mxn= max(mxn, nums[i]);
                neg *= nums[i];
            }
        }
        
        if(allzero) return 0;
        
        if(ncnt > 0 && (ncnt %2)) {
            if(pcnt == 0 && ncnt == 1) return zero? 0: neg; 
            neg = neg / mxn;
        }
        

        if(pcnt == 0) {
            return neg;
        }
        
        return ans * neg;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2708.md" >}}
---
{{< youtube Kqv0-lRVYwM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2710: Remove Trailing Zeros From a String](https://grid47.xyz/leetcode/solution-2710-remove-trailing-zeros-from-a-string/) |
| --- |
