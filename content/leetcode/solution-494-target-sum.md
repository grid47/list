
+++
authors = ["grid47"]
title = "Leetcode 494: Target Sum"
date = "2024-09-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 494: Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/494.webp"
youtube = "Rdie0uPp7e8"
youtube_upload_date="2023-07-19"
youtube_thumbnail="https://i.ytimg.com/vi/Rdie0uPp7e8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/target-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/494.webp" 
    alt="A set of numbers being combined to reach a target sum, with each valid combination softly glowing."
    caption="Solution to LeetCode 494: Target Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<int, map<int, int>> mp;
    vector<int> nums;
    
    int dp(int target, int idx) {
        if(idx == nums.size()) return target == 0;
        
        if(mp.count(target))
            if(mp[target].count(idx)) return mp[target][idx];
        
        int res = dp(target - nums[idx], idx + 1);
        res += dp(target + nums[idx], idx + 1);
        
        return mp[target][idx] = res;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        return dp(target, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/494.md" >}}
---
{{< youtube Rdie0uPp7e8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #497: Random Point in Non-overlapping Rectangles](https://grid47.xyz/leetcode/solution-497-random-point-in-non-overlapping-rectangles/) |
| --- |