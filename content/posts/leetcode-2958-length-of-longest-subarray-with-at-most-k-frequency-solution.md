
+++
authors = ["grid47"]
title = "Leetcode 2958: Length of Longest Subarray With at Most K Frequency"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2958: Length of Longest Subarray With at Most K Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        map<int, int> mp;
        int j = 0, res = 1, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            while(mp[nums[i]] > k) {
                mp[nums[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2958.md" >}}
---
{{< youtube W_KYZGp2QzU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2960: Count Tested Devices After Test Operations](https://grid47.xyz/posts/leetcode-2960-count-tested-devices-after-test-operations-solution/) |
| --- |
