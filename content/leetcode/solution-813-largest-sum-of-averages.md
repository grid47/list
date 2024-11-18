
+++
authors = ["grid47"]
title = "Leetcode 813: Largest Sum of Averages"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 813: Largest Sum of Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/813.webp"
youtube = "3eqwUW6_cx4"
youtube_upload_date="2023-02-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3eqwUW6_cx4/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/largest-sum-of-averages/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/813.webp" 
    alt="A set of averages where the largest sum is calculated, glowing softly as the sum is found."
    caption="Solution to LeetCode 813: Largest Sum of Averages Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double memo[200][200];
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(memo, 0, sizeof(memo));
        int n = nums.size();
        double cur = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            memo[i + 1][1] = cur / (i+ 1);
        }
        return search(n, k, nums);
    }

    double search(int n, int k, vector<int> &nums) {
        if(memo[n][k] > 0) return memo[n][k];
        double cur = 0;
        for(int i = n - 1; i > 0; i--) {
            cur += nums[i];
            memo[n][k] = max(memo[n][k], search(i, k - 1, nums) + cur / (n - i));
        }
        return memo[n][k];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/813.md" >}}
---
{{< youtube 3eqwUW6_cx4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #814: Binary Tree Pruning](https://grid47.xyz/leetcode/solution-814-binary-tree-pruning/) |
| --- |
