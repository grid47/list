
+++
authors = ["grid47"]
title = "Leetcode 2357: Make Array Zero by Subtracting Equal Amounts"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2357: Make Array Zero by Subtracting Equal Amounts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rtGJycuTSUo"
youtube_upload_date="2022-07-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rtGJycuTSUo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mx = 0, res = 0, diff;
        for(int i = 0; i < nums.size(); i++) {
            if(mx < nums[i]) {
                mx = nums[i];
                res++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2357.md" >}}
---
{{< youtube rtGJycuTSUo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2358: Maximum Number of Groups Entering a Competition](https://grid47.xyz/leetcode/solution-2358-maximum-number-of-groups-entering-a-competition/) |
| --- |
