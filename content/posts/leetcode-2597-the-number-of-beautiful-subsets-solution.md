
+++
authors = ["grid47"]
title = "Leetcode 2597: The Number of Beautiful Subsets"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2597: The Number of Beautiful Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Dynamic Programming","Backtracking","Sorting","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-number-of-beautiful-subsets/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> cnt, nums;
    
    int dp(int idx, int k) {
        if(idx == nums.size()) return 1;
        int ans = 0;
        if(nums[idx] - k >= 0 && (cnt[nums[idx] - k] > 0)) {
            ans += dp(idx + 1, k);
        } else {
            ans += dp(idx + 1, k);
            cnt[nums[idx]]++;
            ans += dp(idx + 1, k);
            cnt[nums[idx]]--;            
        }
        return ans;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        cnt.resize(1001, 0);
        this->nums = nums;
        return dp(0, k) - 1; // exluding none selected
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2597.md" >}}
---
{{< youtube Dle_SpjHTio >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2598: Smallest Missing Non-negative Integer After Operations](https://grid47.xyz/posts/leetcode-2598-smallest-missing-non-negative-integer-after-operations-solution/) |
| --- |
