
+++
authors = ["grid47"]
title = "Leetcode 2640: Find the Score of All Prefixes of an Array"
date = "2024-02-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2640: Find the Score of All Prefixes of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xp413jTlTNk"
youtube_upload_date="2023-04-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Xp413jTlTNk/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int mx = nums[0];
        long long sum = 0;
        int n = nums.size();
        vector<long long> ans(n, 0);
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            int scr = nums[i] + mx;
            ans[i] = i == 0? scr: ans[i - 1] + scr;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2640.md" >}}
---
{{< youtube Xp413jTlTNk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2641: Cousins in Binary Tree II](https://grid47.xyz/leetcode/solution-2641-cousins-in-binary-tree-ii/) |
| --- |