
+++
authors = ["grid47"]
title = "Leetcode 974: Subarray Sums Divisible by K"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 974: Subarray Sums Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "bcXy-T4Sc3E"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), sum = 0;        
        vector<int> frq(k, 0);
        frq[0] = 1;
        for(int j = 0; j < n; j++) {
            sum += nums[j];
            int rm = sum % k;
            if(rm < 0) rm += k;            
            res += frq[rm];
            frq[rm]++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/974.md" >}}
---
{{< youtube bcXy-T4Sc3E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #977: Squares of a Sorted Array](https://grid47.xyz/leetcode/solution-977-squares-of-a-sorted-array/) |
| --- |
