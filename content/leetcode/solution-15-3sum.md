
+++
authors = ["grid47"]
title = "Leetcode 15: 3Sum"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 15: 3Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/3sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/15.webp" 
    alt="Three circles of light coming together in harmony, overlapping in a gentle glow."
    caption="Solution to LeetCode 15: 3Sum Problem"
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            while(s < e) {
                if(nums[s] + nums[e] < target) {
                   s++;
                } else if (nums[s] + nums[e] > target) {
                    e--;
                } else {
                    vector<int> res = {nums[i], nums[s], nums[e]};
                    ans.push_back(res);
                    while(s < e && nums[s] == res[1]) s++;
                    while(s < e && res[2] == nums[e]) e--;                    
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/15.md" >}}
---
{{< youtube 8IjCNFIo8YI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #16: 3Sum Closest](https://grid47.xyz/leetcode/solution-16-3sum-closest/) |
| --- |
