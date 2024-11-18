
+++
authors = ["grid47"]
title = "Leetcode 2501: Longest Square Streak in an Array"
date = "2024-03-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2501: Longest Square Streak in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "prcJMNtokGI"
youtube_upload_date="2022-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/prcJMNtokGI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-square-streak-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i= 0; i < n; i++) {
            long long tmp = (long long) nums[i] * nums[i];
            if(tmp > INT_MAX) break;
            auto it = lower_bound(nums.begin(), nums.end(), tmp);
            if(it == nums.end()) break;
            int pos = it - nums.begin();
            while(pos < n && nums[i] * nums[i] == nums[pos]) {
                    dp[pos] = max(dp[pos], 1 + dp[i]);                
                    mx = max(mx, dp[pos]);  
                    pos++;
            }
        }
        return mx == 1? -1: mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2501.md" >}}
---
{{< youtube prcJMNtokGI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2502: Design Memory Allocator](https://grid47.xyz/leetcode/solution-2502-design-memory-allocator/) |
| --- |
