
+++
authors = ["grid47"]
title = "Leetcode 2952: Minimum Number of Coins to be Added"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2952: Minimum Number of Coins to be Added in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "txrhznINlhM"
youtube_upload_date="2023-12-03"
youtube_thumbnail="https://i.ytimg.com/vi/txrhznINlhM/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        int current_max = 0;
        int additions = 0;
        int index = 0;

        while (current_max < target) {
            if (index < coins.size() && coins[index] <= current_max + 1) {
                current_max += coins[index];
                index++;
            } else {
                current_max += current_max + 1;
                additions++;
            }
        }

        return additions;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2952.md" >}}
---
{{< youtube txrhznINlhM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2956: Find Common Elements Between Two Arrays](https://grid47.xyz/leetcode/solution-2956-find-common-elements-between-two-arrays/) |
| --- |