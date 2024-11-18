
+++
authors = ["grid47"]
title = "Leetcode 213: House Robber II"
date = "2024-10-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 213: House Robber II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/213.webp"
youtube = "rWAJCfYYOvM"
youtube_upload_date="2021-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/rWAJCfYYOvM/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/house-robber-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/213.webp" 
    alt="A series of houses arranged in a circle, each glowing with a soft light, showing optimal paths to rob."
    caption="Solution to LeetCode 213: House Robber II Problem"
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
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            
        int r1 = dp[n - 1];
        
        dp.resize(n + 1, 0);
        dp[1] = 0;
        dp[2] = nums[1];        
        for(int i = 3; i < n + 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);        
        
        return max(dp[n], r1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/213.md" >}}
---
{{< youtube rWAJCfYYOvM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #215: Kth Largest Element in an Array](https://grid47.xyz/leetcode/solution-215-kth-largest-element-in-an-array/) |
| --- |
