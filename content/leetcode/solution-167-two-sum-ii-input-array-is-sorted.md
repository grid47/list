
+++
authors = ["grid47"]
title = "Leetcode 167: Two Sum II - Input Array Is Sorted"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 167: Two Sum II - Input Array Is Sorted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/167.webp"
youtube = "ciPrKYoOQkI"
youtube_upload_date="2024-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/ciPrKYoOQkI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/167.webp" 
    alt="A sorted array with glowing pairs of numbers, gently highlighting the solution to the sum."
    caption="Solution to LeetCode 167: Two Sum II - Input Array Is Sorted Problem"
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
        vector<int> ans(2, 0);
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                ans[0] = mp[nums[i]] + 1;
                ans[1] = i + 1;
                return ans;
            } else {
                mp[target - nums[i]] = i;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/167.md" >}}
---
{{< youtube ciPrKYoOQkI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #168: Excel Sheet Column Title](https://grid47.xyz/leetcode/solution-168-excel-sheet-column-title/) |
| --- |