
+++
authors = ["grid47"]
title = "Leetcode 1673: Find the Most Competitive Subsequence"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1673: Find the Most Competitive Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GBJFxSD3B_s"
youtube_upload_date="2021-02-22"
youtube_thumbnail="https://i.ytimg.com/vi/GBJFxSD3B_s/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-most-competitive-subsequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        vector<int> stk;
        for(int i = 0; i < nums.size(); i++) {

            while (!stk.empty()          &&
                 stk.back() > nums[i] &&
                (stk.size() + nums.size() - (i + 1)) >= k )
                stk.pop_back();

            if(stk.size() < k)
                stk.push_back(nums[i]);

        }
        
        return stk;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1673.md" >}}
---
{{< youtube GBJFxSD3B_s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1674: Minimum Moves to Make Array Complementary](https://grid47.xyz/leetcode/solution-1674-minimum-moves-to-make-array-complementary/) |
| --- |