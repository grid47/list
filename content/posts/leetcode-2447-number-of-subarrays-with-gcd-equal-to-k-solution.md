
+++
authors = ["grid47"]
title = "Leetcode 2447: Number of Subarrays With GCD Equal to K"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2447: Number of Subarrays With GCD Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int subarrayGCD(vector<int>& nums, int k) {        
        int cnt = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n && nums[j] % k == 0; j++) {
                nums[i] = __gcd(nums[i], nums[j]);
                cnt += (nums[i] == k);
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2447.md" >}}
---
{{< youtube QEvLvINq730 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2451: Odd String Difference](https://grid47.xyz/posts/leetcode-2451-odd-string-difference-solution/) |
| --- |
