
+++
authors = ["grid47"]
title = "Leetcode 2567: Minimum Score by Changing Two Elements"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2567: Minimum Score by Changing Two Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MPtncVNtKW0"
youtube_upload_date="2023-02-18"
youtube_thumbnail="https://i.ytimg.com/vi/MPtncVNtKW0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[n - 3] - nums[0];
        int b = nums[n - 1] - nums[2];
        int c = nums[n - 2] - nums[1];
        return min({a, b, c});
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2567.md" >}}
---
{{< youtube MPtncVNtKW0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2568: Minimum Impossible OR](https://grid47.xyz/leetcode/solution-2568-minimum-impossible-or/) |
| --- |