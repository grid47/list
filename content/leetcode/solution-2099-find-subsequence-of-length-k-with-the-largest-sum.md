
+++
authors = ["grid47"]
title = "Leetcode 2099: Find Subsequence of Length K With the Largest Sum"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2099: Find Subsequence of Length K With the Largest Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QXvaOym_Awk"
youtube_upload_date="2021-12-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QXvaOym_Awk/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v(nums.begin(), nums.end());
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
        int cnt = count(v.begin(), v.begin() + k, v[k - 1]);
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
            if((nums[i] > v[k - 1]) ||
               (nums[i] == v[k - 1] && (cnt-- > 0)))
                res.push_back(nums[i]);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2099.md" >}}
---
{{< youtube QXvaOym_Awk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2100: Find Good Days to Rob the Bank](https://grid47.xyz/leetcode/solution-2100-find-good-days-to-rob-the-bank/) |
| --- |
