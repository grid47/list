
+++
authors = ["grid47"]
title = "Leetcode 2932: Maximum Strong Pair XOR I"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2932: Maximum Strong Pair XOR I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Trie","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-strong-pair-xor-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++) {
            if((nums[j] - nums[i] <= nums[i]) && (res <= (nums[i] ^ nums[j]))){
                // cout << nums[i] << " " << nums[j] << "\n";
                res = max(res, nums[i] ^ nums[j]);
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2932.md" >}}
---
{{< youtube n6CncKaYGwk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2933: High-Access Employees](https://grid47.xyz/posts/leetcode-2933-high-access-employees-solution/) |
| --- |
