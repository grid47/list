
+++
authors = ["grid47"]
title = "Leetcode 2210: Count Hills and Valleys in an Array"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2210: Count Hills and Valleys in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "I9ZXvpleMDk"
youtube_upload_date="2022-03-20"
youtube_thumbnail="https://i.ytimg.com/vi/I9ZXvpleMDk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countHillValley(vector<int>& nums) {
      int res = 0;
        for(int j = 0, i = 1; i < nums.size() - 1; i++)
          if ((nums[j] < nums[i] && nums[i] > nums[i + 1]) ||
              (nums[j] > nums[i] && nums[i] < nums[i + 1])) {
                res++;
                j = i;
              }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2210.md" >}}
---
{{< youtube I9ZXvpleMDk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2211: Count Collisions on a Road](https://grid47.xyz/leetcode/solution-2211-count-collisions-on-a-road/) |
| --- |