
+++
authors = ["grid47"]
title = "Leetcode 1658: Minimum Operations to Reduce X to Zero"
date = "2024-05-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1658: Minimum Operations to Reduce X to Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = -1;
        long sum = -x;
        for(int y: nums) sum += y;
        int n = nums.size();
        if (sum == 0) return n;
        
        map<int, int> mp;
        mp[0] = -1;
        int s = 0;
        for(int i = 0; i < n; i++) {
            s += nums[i];
            if(mp.count(s - sum)) {
                res = max(res, i - mp[s - sum]);
            }
            mp[s] = i;
        }
        
        return res == -1? res :n - res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1658.md" >}}
---
{{< youtube iPqrN6Bb-NI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1662: Check If Two String Arrays are Equivalent](https://grid47.xyz/posts/leetcode-1662-check-if-two-string-arrays-are-equivalent-solution/) |
| --- |
