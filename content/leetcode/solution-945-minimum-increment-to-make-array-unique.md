
+++
authors = ["grid47"]
title = "Leetcode 945: Minimum Increment to Make Array Unique"
date = "2024-08-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 945: Minimum Increment to Make Array Unique in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XPPs2Wj2YSk"
youtube_upload_date="2024-06-14"
youtube_thumbnail="https://i.ytimg.com/vi/XPPs2Wj2YSk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0, n = nums.size(), need = 0;
        for(int i = 0; i < n; i++) {
            res += max(need - nums[i], 0);
            need = max(nums[i], need) + 1;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/945.md" >}}
---
{{< youtube XPPs2Wj2YSk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #946: Validate Stack Sequences](https://grid47.xyz/leetcode/solution-946-validate-stack-sequences/) |
| --- |