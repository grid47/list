
+++
authors = ["grid47"]
title = "Leetcode 1: Two Sum"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1: Two Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/1.webp"
youtube = "Yyyi12oaK94"
youtube_upload_date="2022-08-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Yyyi12oaK94/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/two-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/1.webp" 
    alt="A pair of floating, glowing puzzle pieces coming together in a soft light."
    caption="Solution to LeetCode 1: Two Sum Problem"
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
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                return { mp[nums[i]], i };
            } else {
                mp[target - nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1.md" >}}
---
{{< youtube Yyyi12oaK94 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2: Add Two Numbers](https://grid47.xyz/leetcode/solution-2-add-two-numbers/) |
| --- |