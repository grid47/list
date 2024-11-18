
+++
authors = ["grid47"]
title = "Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three"
date = "2023-12-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3190: Find Minimum Operations to Make All Elements Divisible by Three in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "b-UBMai1bGM"
youtube_upload_date="2024-06-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b-UBMai1bGM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++) ans+=min(3-(nums[i]%3),nums[i]%3);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3190.md" >}}
---
{{< youtube b-UBMai1bGM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/)  |
| --- |
