
+++
authors = ["grid47"]
title = "Leetcode 1712: Ways to Split Array Into Three Subarrays"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1712: Ways to Split Array Into Three Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1000000007;
public:
    int waysToSplit(vector<int>& nums) {
        
        int n = nums.size(), res=0;

        partial_sum(nums.begin(), nums.end(), nums.begin());
        
        for(int i = 0, j = 0, k = 0; i < n - 2; i++) {

            j = max(i + 1, j);
            while(j < n - 1 && 2 * nums[i] > nums[j]) j++;

            k = max(j, k);
            while(k < n - 1 && nums[k] - nums[i] <= nums[n - 1] - nums[k]) k++;

            res = (res + (k - j)) % mod;
        }
        return res;            
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1712.md" >}}
---
{{< youtube u5GIK6GaNWk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1716: Calculate Money in Leetcode Bank](https://grid47.xyz/leetcode/solution-1716-calculate-money-in-leetcode-bank/) |
| --- |
