
+++
authors = ["grid47"]
title = "Leetcode 2587: Rearrange Array to Maximize Prefix Score"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2587: Rearrange Array to Maximize Prefix Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "N3qkc7zT_a0"
youtube_upload_date="2023-03-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/N3qkc7zT_a0/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        
        if(n == 1) return nums[0] > 0;
        int cnt = 0;
        
        long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum > 0) cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2587.md" >}}
---
{{< youtube N3qkc7zT_a0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2588: Count the Number of Beautiful Subarrays](https://grid47.xyz/leetcode/solution-2588-count-the-number-of-beautiful-subarrays/) |
| --- |