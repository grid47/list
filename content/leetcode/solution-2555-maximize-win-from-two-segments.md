
+++
authors = ["grid47"]
title = "Leetcode 2555: Maximize Win From Two Segments"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2555: Maximize Win From Two Segments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "trj4pn5uzZ0"
youtube_upload_date="2023-02-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/trj4pn5uzZ0/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximize-win-from-two-segments/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {
        
        int n = pos.size(), res = 0;
        
        vector<int> dp(n + 1, 0);
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(pos[j] < pos[i] - k) j++;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1+ dp[j]);
        }
        
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2555.md" >}}
---
{{< youtube trj4pn5uzZ0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2556: Disconnect Path in a Binary Matrix by at Most One Flip](https://grid47.xyz/leetcode/solution-2556-disconnect-path-in-a-binary-matrix-by-at-most-one-flip/) |
| --- |
