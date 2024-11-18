
+++
authors = ["grid47"]
title = "Leetcode 2780: Minimum Index of a Valid Split"
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2780: Minimum Index of a Valid Split in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-index-of-a-valid-split/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        int dom = -1;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(2 * mp[nums[i]] > n) {
                dom = nums[i];
            }
        }
        
        int frq = mp[dom];
        
        int l = 0, r = frq;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == dom) {
                l++;
                r--;
            }
            if(2 * l > (i + 1) && 2 * r > (n - (i + 1)))
                return i;
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2780.md" >}}
---
{{< youtube qhvhUTBnYd8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2784: Check if Array is Good](https://grid47.xyz/leetcode/solution-2784-check-if-array-is-good/) |
| --- |
