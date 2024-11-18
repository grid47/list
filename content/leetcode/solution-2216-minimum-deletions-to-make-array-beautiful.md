
+++
authors = ["grid47"]
title = "Leetcode 2216: Minimum Deletions to Make Array Beautiful"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2216: Minimum Deletions to Make Array Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "VgyrTbLZie8"
youtube_upload_date="2022-03-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/VgyrTbLZie8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == nums[i + 1] && (i - ans) % 2 == 0) ans++;
        
        return ans + (nums.size() - ans) % 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2216.md" >}}
---
{{< youtube VgyrTbLZie8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2217: Find Palindrome With Fixed Length](https://grid47.xyz/leetcode/solution-2217-find-palindrome-with-fixed-length/) |
| --- |
