
+++
authors = ["grid47"]
title = "Leetcode 486: Predict the Winner"
date = "2024-09-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 486: Predict the Winner in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Recursion","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/486.webp"
youtube = "KjlXtj7IwyY"
youtube_upload_date="2022-10-03"
youtube_thumbnail="https://i.ytimg.com/vi/KjlXtj7IwyY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/predict-the-winner/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/486.webp" 
    alt="A glowing sequence where the winner is predicted based on optimal strategies, with each move softly glowing."
    caption="Solution to LeetCode 486: Predict the Winner Problem"
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
    
    vector<int> nums;
    vector<vector<map<int, int>>> memo;
    
    int dp(int l, int r, int net) {
        
        if(l == r) return nums[l];
        
        if(memo[l][r].count(net)) return memo[l][r][net];
        
        int ans = net - dp(l + 1, r, net - nums[l]);
        ans = max(ans, net - dp(l, r - 1, net - nums[r]));
        
        return memo[l][r][net] = ans;
    }
    
    bool predictTheWinner(vector<int>& nums) {

        this->nums = nums;
        int n = nums.size();
        memo.resize(n + 1, vector<map<int,int>>(n + 1));
        
        int net = accumulate(nums.begin(), nums.end(), 0);
        
        int ret = dp(0, n - 1, net);

        return ret >= net - ret;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/486.md" >}}
---
{{< youtube KjlXtj7IwyY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #494: Target Sum](https://grid47.xyz/leetcode/solution-494-target-sum/) |
| --- |
