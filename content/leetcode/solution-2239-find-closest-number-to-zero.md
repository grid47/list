
+++
authors = ["grid47"]
title = "Leetcode 2239: Find Closest Number to Zero"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2239: Find Closest Number to Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "dLlKA5DQKYs"
youtube_upload_date="2024-07-03"
youtube_thumbnail="https://i.ytimg.com/vi/dLlKA5DQKYs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-closest-number-to-zero/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int findClosestNumber(vector<int>& nums) {
    return *min_element(begin(nums), end(nums), [](int a, int b) {
        return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
    });
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2239.md" >}}
---
{{< youtube dLlKA5DQKYs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2240: Number of Ways to Buy Pens and Pencils](https://grid47.xyz/leetcode/solution-2240-number-of-ways-to-buy-pens-and-pencils/) |
| --- |
