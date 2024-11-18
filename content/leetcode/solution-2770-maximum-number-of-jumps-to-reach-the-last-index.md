
+++
authors = ["grid47"]
title = "Leetcode 2770: Maximum Number of Jumps to Reach the Last Index"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2770: Maximum Number of Jumps to Reach the Last Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_al08ON26RA"
youtube_upload_date="2023-07-09"
youtube_thumbnail="https://i.ytimg.com/vi/_al08ON26RA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int target, n;
    vector<int> memo, nums;
    
    int dp(int idx) {
        
        if(idx == n - 1) return 0;
        
        if(memo[idx] != INT_MIN) return memo[idx];
        
        int ans = INT_MIN;
        for(int i = idx + 1; i < n; i++) {
            if(abs(nums[i] - nums[idx]) <= target) {
                ans = max(ans, dp(i) + 1);
            }
        }
        // cout << idx << " " << ans << "\n";
        return memo[idx] = ans;
    }
    
    int maximumJumps(vector<int>& nums, int target) {

        n = nums.size();
        this->target = target;
        this->nums = nums;
        memo.resize(n, INT_MIN);
        int ans = dp(0);
        return ans <= 0? -1: ans;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2770.md" >}}
---
{{< youtube _al08ON26RA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2771: Longest Non-decreasing Subarray From Two Arrays](https://grid47.xyz/leetcode/solution-2771-longest-non-decreasing-subarray-from-two-arrays/) |
| --- |
