
+++
authors = ["grid47"]
title = "Leetcode 2439: Minimize Maximum of Array"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2439: Minimize Maximum of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Greedy","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AeHMvcKuR0Y"
youtube_upload_date="2023-04-05"
youtube_thumbnail="https://i.ytimg.com/vi/AeHMvcKuR0Y/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimize-maximum-of-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, (sum + i) / (i + 1));
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2439.md" >}}
---
{{< youtube AeHMvcKuR0Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2441: Largest Positive Integer That Exists With Its Negative](https://grid47.xyz/leetcode/solution-2441-largest-positive-integer-that-exists-with-its-negative/) |
| --- |