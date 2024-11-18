
+++
authors = ["grid47"]
title = "Leetcode 2256: Minimum Average Difference"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2256: Minimum Average Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-average-difference/description/)

---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        typedef long long ll;
        
        ll sum = 0;
        for(int a : nums) sum += a;

        ll n = nums.size(), res = INT_MAX, ret = 0, la = 0, ra = 0;
        ll l = 0, r = sum;
        for(int i = 0; i < n; i++) {
            int prv = res;
            l += nums[i];
            r -= nums[i];      
            la = l / (i + 1);
            ra = (i+1==n)?0:r / (n-(i+1));
            res = min(res, abs(la - ra));
            if(prv != res) ret = i;
        }
        return ret;            
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2256.md" >}}
---
{{< youtube rh8Mnj9Bd64 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2257: Count Unguarded Cells in the Grid](https://grid47.xyz/leetcode/solution-2257-count-unguarded-cells-in-the-grid/) |
| --- |
